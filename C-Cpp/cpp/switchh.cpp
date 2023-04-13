#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Factorial(int num)
{
    int ansNum = num;
    for (int j = 1; j < num; j++)
    {
        ansNum *= (num - j);
    }
    return ansNum;
}
string primeOrNot(int num)
{
    if (num == 0)
    {
        return "not pri";
    }
    int pri = num / 2;
    for (int i = 2; i <= pri; i++)
    {
        int rem = num % i;
        if (rem == 0)
        {
            return "Not Prime NO";
        }
    }
    return "prime";
}
string checkEvenOrOdd(int num)
{
    if (num % 2 == 0)
    {
        return "Even";
    }
    else
    {
        return "Odd";
    }
}

int main()
{
    int choice, num;
    vector<string> printText = {"1. Factorial Of a No.", "2. Prime Or Not", "3. Odd Or Even No", "4. Exit", "please input your choice in number"};
    do
    {

        for (int i = 0; i < printText.size(); i++)
        {
            cout << printText[i] << endl;
        }

        cin >> choice;
        if (choice != 4)
        {
            cout << "please input your number" << endl;
            cin >> num;
        }
        switch (choice)
        {
        case 1:
            cout << Factorial(num) << endl;
            break;
        case 2:
            cout << primeOrNot(num) << endl;
            break;
        case 3:
            cout << checkEvenOrOdd(num) << endl;
            break;
        case 4:
            cout << "Exiting.." << endl;
            break;

        default:
            cout << "Please Enter Correct Number!!" << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}