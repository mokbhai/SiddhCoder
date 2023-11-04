#include<iostream>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=this->right=NULL;
    }
};

class BTH{
    Node* root;

    void insert(Node* root, int arr[],int size){
        if(root==NULL){}
    }



};

int main(){
    int arr[5]={1,3,4,5,2}; //5,2,3,4,1
    int size=5;
    return 0;
}
