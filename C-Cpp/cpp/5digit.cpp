#include <bits/stdc++.h>

using namespace std;

int sumOfDigit(int num)
{
    int modul, sum = 0;

    for (int i = 0; i < 5; i++)
    {
        modul = num % 10;
        num /= 10;
        sum += modul;
    }
    return sum;
}

int count(int num)
{
    int count = 0;
    while (num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

int reverse(int num)
{
    int modul, sum = 0;
    int size = count(num);
    for (int i = size - 1; i >= 0; i--)
    {
        modul = num % 10;
        num /= 10;
        sum += modul * pow(10, i);
    }
    return sum;
}

int sumOfFirstLast(int num)
{
    int modul, sum = 0;
    int size = count(num);
    modul = num % 10;
    num = num / pow(10, size - 1);
    sum = modul + num;
    return sum;
}

int main()
{
    int num, result;
    cin >> num;

    result = sumOfFirstLast(num);
    cout << result << endl;
    return 0;
}
