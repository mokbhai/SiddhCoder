// You are using GCC
#include <iostream>

using namespace std;

class Node
{
public:
    Node* pre;
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = nullptr;
        pre = nullptr;
    }
};

class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    
    bool isEmpty()
    {
        return front == nullptr;
    }
    
    void enqueue(int val)
    {
        Node* newNode = new Node(val);
        // cout << val << " ";
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            newNode->next = rear;
            rear->pre = newNode;
            rear = newNode;
        }
    }
    
    void display()
    {
        Node* tf = front;
        Node* tr = rear;
        
        while (tf != nullptr && tr != nullptr)
        {
            // prints in zigzag format
            // cout << tf->data << " ";
            // cout << tr->data << " ";

            cout << "H ";
            // tf = tf->next;
            // tr = tr->pre;
        }
    }
};

int main()
{
    Queue queue;
    int n, q;
    cin >> n;
    
    cin >> q;
    while (q != -1)
    {
        // cout << q << " ";
        queue.enqueue(q);
        cin >> q;
    }
    queue.display();
}