#include <iostream>
#include <bits/stdc++.h>

using namespace std;

optional<int> simpleCalculations(int num1, int num2, char op)
{
    optional<int> result;
    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 == 0) {
            cout << "num 2 cannot be 0" << endl;
            break;
        }
        result = num1 / num2;
        break;

    default:
        cout << "enter another operator" << endl;
        break;
    }
    return result;
}

int main()
{
    int num1, num2;
    cout << "Input 2 numbers" << endl;
    cin >> num1 >> num2;

    char op;
    cout << "Input operator(+, -, *, /)" << endl;
    cin >> op;

    optional<int> result = simpleCalculations(num1, num2, op);
    if (result.has_value())
    {
        cout << result.value();
    }
    return 0;
}