// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}


Node* deleteEvenNodes(Node* root) {
    if (root == nullptr)
        return nullptr;

    if (root->data % 2 == 0) {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* minRightSubtree = root->right;
            while (minRightSubtree->left != nullptr) {
                minRightSubtree = minRightSubtree->left;
            }
            root->data = minRightSubtree->data;
            root->right = deleteEvenNodes(root->right);
        }
    }

    root->left = deleteEvenNodes(root->left);
    root->right = deleteEvenNodes(root->right);

    return root;
}

void printBST(Node* root) {
    //Type your code
    if (root == nullptr)
        return; 
    printBST(root->left);
    std::cout << root->data << " ";
    printBST(root->right);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insert(root, data);
    }

    root = deleteEvenNodes(root);
    printBST(root);
    return 0;
}
