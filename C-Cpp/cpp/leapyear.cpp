#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int year;
    cout << "Input year" << endl;
    cin >> year;
    year %= 4;
    if (year == 0)
    {
        cout << "this year is a leap year" << endl;
    }
    else
    {
        cout << "this year is not a leap year" << endl;
    }
    return 0;
}