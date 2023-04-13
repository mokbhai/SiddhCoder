#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1000, 500, 200, 100, 50, 10, 5, 2, 1};
    int num;
    cin >> num;
    int sumNotes = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (num < arr[i]) {
            continue;
        }
        int reminder = num % arr[i];
        int noteCount = num / arr[i];
        sumNotes += noteCount;
        num = reminder;
        // if (num >= arr[i])
        // {
        //     num = num % arr[i];
        //     totalValue /= arr[i];
        //     sumNotes += totalValue;
        cout << " note rs " << arr[i] << " = " << noteCount << endl;
        // }
    }
    return 0;
}