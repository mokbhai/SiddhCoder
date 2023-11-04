// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

//Function to create a new node
Node* createNode(int data) {
    
    //Type your code here
    Node* newNode = new Node();
    
    newNode->data = data;
    newNode->left = nullptr; 
    newNode->right = nullptr;
    return newNode;
}

//Function to build the tree
Node* insertNode(Node* root, int data) {
    
    //Type your code here
    if (root == nullptr)
        return createNode(data);
    
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    
    return root;
    
}

//Function to perform the preorder traversal
void preorderTraversal(Node* root) {
    
    //Type your code here
    if (root == nullptr)
        return;
        
    cout << root->data << " ";
    
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorder(struct Node* temp) {
    if (temp == NULL) {
        return;
    }

    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

int main() {
    Node* root = nullptr;
    int n, data;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> data;
        root = insertNode(root, data);
    }
    cout << "Preorder: ";
    preorderTraversal(root);
    cout << "\ninorder:  ";
    inorder(root);
    free(root);
    return 0;
}