// Performing operations using stack; Zero address operations;

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    int a, b;
    cin >> a >> b;

    s.push(a);
    s.push(b);

    int c = s.top();
    s.pop();
    c *= s.top();
    s.pop();
    s.push(c);

    return 0;
}