// You are using GCC
#include <iostream>

using namespace std;
const int MAX_N = 100;

int isConsonant(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' &&
            ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') {
            return 1;
        }
    }
    return 0;
}

void merge(char arr[], int left, int mid, int right, int carr[]) {
    
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    char l[n1], r[n2];
    
    int i = 0, j = 0, k = left;
    
    for (i = 0; i < n1; i++)
        l[i] = arr[left+i];
    for (i = 0; i < n2; i++)
        r[i] = arr[mid+i+1];
    i = 0;
    while (i < n1 && j < n2)
    {
        if ((l[i] <= r[j] || carr[j]) && !carr[i])
        {
            arr[k] = l[i];
            l[i] = 0;
            i++;
            k++;
        }
        else if (!carr[j])
        {
            arr[k] = r[j];
            r[j] = 0;
            j++;
            k++;
        }
        else if (!carr[i])
        {
            i++;
        }
        else if (!carr[j])
        {
            j++;
        }
    }
    i = 0; j = 0;
    while (i < n1)
    {
        if (l[i] != 0)
            arr[k] = l[i];
        
        i++;
    }
    while (j < n2)
    {
        if (r[j] != 0)
            arr[k] = r[j];
        
        j++;
    }
    
}

void mergeSort(char arr[], int left, int right, int carr[]) {
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid, carr);
        mergeSort(arr, mid+1, right, carr);
        
        merge(arr, left, mid, right, carr);
    }
    
}

int main() {
    int n;
    cin >> n;

    char characters[MAX_N];
    int consonant_count[MAX_N];

    for (int i = 0; i < n; i++) {
        cin >> characters[i];
        consonant_count[i] = isConsonant(characters[i]);
    }

    mergeSort(characters, 0, n - 1, consonant_count);

    for (int i = 0; i < n; i++) {
        cout << characters[i] << " ";
    }

    return 0;
}