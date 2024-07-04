import java.util.LinkedList;
import java.util.Queue;

public class PreOrderTree {

    static class Node {
        int data;
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    static class BinaryTree {
        static int idx = -1;

        public static Node buildTree(int nodes[]) {
            idx++;
            if (nodes[idx] == -1) {
                return null;
            }
            Node newNode = new Node(nodes[idx]);
            newNode.left = buildTree(nodes);
            newNode.right = buildTree(nodes);
            return newNode;
        }

        public static void preOrder(Node root) {
            if (root == null) {
                System.out.print("-1 ");
                return;
            }
            System.out.print(root.data + " ");
            preOrder(root.left);
            preOrder(root.right);
        }

        public static void inOrder(Node root) {
            if (root == null) {
                System.out.print("-1 ");
                return;
            }
            inOrder(root.left);
            System.out.print(root.data + " ");
            inOrder(root.right);
        }

        public static void postOrder(Node root) {
            if (root == null) {
                System.out.print("-1 ");
                return;
            }
            postOrder(root.left);
            postOrder(root.right);
            System.out.print(root.data + " ");
        }

        public static void levelOrder(Node root) {
            Queue<Node> queue = new LinkedList<Node>();
            queue.add(root);
            Node minusone = new Node((-1));
            while (!queue.isEmpty()) {
                Node temp = queue.poll();
                System.out.print(temp.data + " ");

                if (temp.data == -1) {
                    continue;
                }

                if (temp.left != null) {
                    queue.add(temp.left);
                } else {
                    queue.add(minusone);
                }

                if (temp.right != null) {
                    queue.add(temp.right);
                } else {
                    queue.add(minusone);
                }
            }
        }
    }

    public static void main(String[] args) {
        int nodes[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };

        BinaryTree.idx = -1;
        Node root = BinaryTree.buildTree(nodes);

        System.out.println("PreOrder Traversal:");
        BinaryTree.preOrder(root);
        System.out.println();

        System.out.println("InOrder Traversal:");
        BinaryTree.inOrder(root);
        System.out.println();

        System.out.println("PostOrder Traversal:");
        BinaryTree.postOrder(root);
        System.out.println();

        System.out.println("LevelOrder Traversal:");
        BinaryTree.levelOrder(root);
        System.out.println();
    }
}
