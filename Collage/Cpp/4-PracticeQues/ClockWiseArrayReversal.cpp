#include <iostream>
using namespace std;

void reverse(vector<int>& arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5}; // Original array
    int n = 5; 
    int k = 3;

    k = k % n;
    
    // Reverse the first part, the second part, and then the whole array
    reverse(arr, 0, n - k - 1);
    reverse(arr, n - k, n - 1);
    reverse(arr, 0, n - 1);
    
    
    // Print the modified array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}