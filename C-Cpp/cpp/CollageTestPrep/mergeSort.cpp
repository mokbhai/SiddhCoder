#include <iostream>

using namespace std;
const int MAX_N = 100;

void merge(int c[], int left, int mid, int right) {
    
    int n1 = mid - left + 1, n2 = right - mid;
    
    char l[n1], r[n2];
    int i = 0, j = 0, k = left;
    
    // add data to temp arrays
    while (i < n1)
    {
        l[i] = c[left+i];
        i++;
    }
    while (j < n2)
    {
        r[j] = c[mid+j+1];
        j++;
    }
    
    i = 0;
    j = 0;
    
    // Sort
    while (i < n1 && j < n2)
    {
        if (l[i] < r[j])
        {
            c[k] = l[i];
            i++;
        }
        else
        {
            c[k] = r[j];
            j++;
        }
        k++;
    }
    
    // add left as same
    while (i < n1)
    {
        c[k++] = l[i++];
    }
    while (j < n2)
    {
        c[k++] = r[j++];
    }
}

void mergeSort(int c[], int left, int right) {
    //Type your code here
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        
        mergeSort(c, left, mid);
        mergeSort(c, mid + 1, right);
        
        merge(c, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    int characters[MAX_N];
    int consonant_count[MAX_N];

    for (int i = 0; i < n; i++) {
        cin >> characters[i];
    }

    mergeSort(characters, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << characters[i] << " ";
    }

    return 0;
}