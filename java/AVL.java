public class AVL {
    static class Node {
        int data, height;
        Node left, right;

        Node(int data) {
            this.data = data;
            height = 1;
        }
    }

    public static Node root;

    public static int height(Node root) {
        if (root == null) {
            return 0;
        }

        return root.height;
    }

    public static Node rightRotate(Node y) {

        Node x = y.left;
        Node t2 = x.right;

        x.right = y;
        y.left = t2;

        y.height = Math.max(height(y.left), height(y.right)) + 1;
        x.height = Math.max(height(x.right), height(x.left)) + 1;

        return x;
    }

    public static Node leftRotate(Node x) {

        Node y = x.right;
        Node t2 = y.left;

        y.left = x;
        x.right = t2;

        y.height = Math.max(height(y.left), height(y.right)) + 1;
        x.height = Math.max(height(x.right), height(x.left)) + 1;

        return y;
    }

    public static int getBalance(Node root) {
        if (root == null) {
            return 0;
        }

        return height(root.left) - height(root.right);
    }

    Node insert(Node node, int data) {

        if (node == null)
            return (new Node(data));

        if (data < node.data)
            node.left = insert(node.left, data);
        else if (data > node.data)
            node.right = insert(node.right, data);
        else
            return node;

        node.height = 1 + Math.max(height(node.left),
                height(node.right));

        int balance = getBalance(node);

        if (balance > 1 && data < node.left.data)
            return rightRotate(node);

        if (balance < -1 && data > node.right.data)
            return leftRotate(node);

        if (balance > 1 && data > node.left.data) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node.right.data) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        return node;
    }

    void preOrder(Node node) {
        if (node != null) {
            System.out.print(node.data + " ");
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    public static void main(String[] args) {
        AVL tree = new AVL();

        tree.root = tree.insert(tree.root, 10);
        tree.root = tree.insert(tree.root, 20);
        tree.root = tree.insert(tree.root, 30);
        tree.root = tree.insert(tree.root, 40);
        tree.root = tree.insert(tree.root, 50);
        tree.root = tree.insert(tree.root, 25);

        System.out.println("Preorder traversal" +
                " of constructed tree is : ");
        tree.preOrder(tree.root);
    }
}