#include <iostream>
#include <queue>
using namespace std;

queue<int> q1, q2;

void push(int data) {
    q1.push(data);
}

int pop() {
    if (q1.empty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }

    // Move all elements except the last one from q1 to q2
    while (q1.size() > 1) {
        q2.push(q1.front());
        q1.pop();
    }

    // The last element in q1 is the one to pop
    int data = q1.front();
    q1.pop();

    // Swap q1 and q2 to keep q1 as the primary queue
    swap(q1, q2);

    return data;
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << pop() << endl; // 30
    cout << pop() << endl; // 20
    cout << pop() << endl; // 10
    cout << pop() << endl; // Queue is empty

    return 0;
}
