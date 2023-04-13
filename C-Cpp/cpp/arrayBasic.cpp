#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// int binearySearch(int array[], int n, int key)
// {
//     int s = 0, e = n;
//     do
//     {
//         int mid = (s + e) / 2;
//         if (array[mid] == key)
//         {
//             return mid;
//         }
//         else if (array[mid] > key)
//         {
//             e = mid - 1;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//     } while (s <= e);
//     return -1;
// }

int* selectionSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[i])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    return array;
}

// int bubbleSort()
// {
// }

int main()
{
    int n;
    cout << "input array length" << endl;
    cin >> n;

    int array[n /*size of array*/]; //= {10, 20, 30, 40, 50};
                                    // OR
                                    /*   int array[4];
                                       array[0] = 1;
                                       array[1] = 2;
                                       array[2] = 3;
                                       array[3] = 4;
                                   */
    cout << "input array charaters" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int key;
    cout << "input value to be found" << endl;
    cin >> key;
    int* arrStore = selectionSort(array, n);
    // cout << binearySearch(array, n, key) << endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arrStore[i]<<" ";
    }









    switch (expression)
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }
    

    // cout << bubbleSort(array, n) << endl;
    return 0;
}