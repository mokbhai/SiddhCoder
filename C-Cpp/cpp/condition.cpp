#include <bits/stdc++.h>

using namespace std;

// namespace -> class -> func
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

string prime(int num)
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

int main()
{
    // int num;
    // cin >> num;
    // cout << checkEvenOrOdd(num);
    int prim;
    cin >> prim;
    cout << prime(prim) << endl;
    cout << prime(prim);
    return 0;
}