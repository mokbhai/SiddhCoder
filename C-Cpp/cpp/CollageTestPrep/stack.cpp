#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Function to get the top element of the stack
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return -1; // Return a default value or throw an exception if desired
        }
        return top->data;
    }

    // reverse the display
    void display(Node* temp)
    {
        if (temp == nullptr)
            return;
        
        display(temp->next);
        std::cout << temp->data << " ";
    }

    // Function to display the stack
    void display() {
        Node* current = top;

        display(current);
        // while (current != nullptr) {
        //     std::cout << current->data << " ";
        //     current = current->next;
        // }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    std::cout << "Stack elements: ";
    stack.display();

    // std::cout << "Top element: " << stack.peek() << std::endl;

    // stack.pop();
    // std::cout << "After popping: ";
    // stack.display();

    return 0;
}
