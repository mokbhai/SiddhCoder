#include <iostream>
#include <vector>
using namespace std;

void numberOfDigits(string& num, int& count) {
    if (num.length() == 0) return;
    num.pop_back();
    numberOfDigits(num, ++count);
} 

// int main() {
//     string num; int count = 0;
//     cin >> n;
//     numberOfDigits(num, count);
//     cout << count;
// }

void numberOfEvenPresentInArray(int* arr, int& size, int& i, int& count) {
    if (size == i) return;
    if (arr[i] % 2 == 0) ++count;
    numberOfEvenPresentInArray(arr, size, ++i, count);
}

// int main() {
//     int size = 10, i = 0, count = 0;
//     int arr[] = {2, 2, 2, 4, 6, 7, 8, 9, 9, 11};
//     numberOfEvenPresentInArray(arr, size, i, count);
//     cout << "number of even present in array: " << count << endl;
//     return 0;
// }

void countTheRepeatedElements(int* arr, int& size, int& i, int& idx) {
    if (size == i || idx != -1) return;

    if (arr[i] == arr[i-1])
        idx = i;
    else
        countTheRepeatedElements(arr, size, ++i, idx);
}

int main() {

    int i = 1, idx = -1;
    int arr[] = {2, 2, 2, 4, 6, 7, 8, 9, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]); 
    countTheRepeatedElements(arr, size, i, idx);

    if (idx != -1)
        cout << "The first repeated element is: " << arr[idx] << endl;
    else 
        cout << "No Repeated Element Found" << endl;

    return 0;
}