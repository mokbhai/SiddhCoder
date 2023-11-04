// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    //Type your code here
    if (root == nullptr)
    {
        root = new Node(data);
        return root;
    }
    
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root-> right = insert(root->right, data);
    return root;
}

void postOrder(Node* root) {
    //Type your code here
    if (root == nullptr)
        return;
    
    postOrder(root->left);
    // cout << root->data << " ";
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int n;
    int data;

    cin >> n;

    while (n-- > 0) {
        cin >> data;
        root = insert(root, data);
    }

    postOrder(root);
    return 0;
}