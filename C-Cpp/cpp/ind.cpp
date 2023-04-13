#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// parameter
// return type
int testFunc(int a, int b)
{
    return a + b;
}

int sum3intFunc(int a, int b, int c)
{
    return a + b + c;
}

// argument
int main()
{
    int a;     // define
    int b = 1; // define + intialize
    a = 2;     // intialize
    int c;
    cin >> c;
    cout << testFunc(a, b);

    int result = sum3intFunc(a, b, c);
    cout << result;
}