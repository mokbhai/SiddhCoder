#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5}; // Original array
    int n = 5; 
    int k = 3;

    // Reverse the first n-k elements
    for (int i = 0; i < (n - k) / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - k - i - 1];
        arr[n - k - i - 1] = temp;
    }
    
    // Reverse last k elements
    for (int i = 0; i < k / 2; i++) {
        int temp = arr[n - k + i];
        arr[n - k + i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    
    
    // Print the modified array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}