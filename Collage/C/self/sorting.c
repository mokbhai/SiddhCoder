// Errored
#include <stdio.h>

// passing 3 arguments in sortArr as array, left half size and right half size
void sortArr(int [], int, int);
// merge array
void mergeArr(int [], int, int, int);
// print array
void printArr(int [], int);

int main(void)
{
    // array
    int arr[] = {1, 6, 10, 8, 7, 2, 5, 4, 9, 3};
    // finding size of array
    int size_of_arr = sizeof(arr) / sizeof(arr[0]);
    //printing arr so to let user see what array is
    printArr(arr, size_of_arr);

    // passing 3 arguments as array, left half size and right half size
    sortArr(arr, 0, size_of_arr - 1);
    printArr(arr, size_of_arr);
}

void printArr(int arr[], int size)
{
    printf("{ %d", arr[0]);
    for (int i = 1; i < size; i++)
        printf(", %d", arr[i]);
    printf(" }\n");
}

// left is the left index while right is right index
void sortArr(int arr[], int left, int right)
{
    if (left < right)
    {
        // mid index
        int mid = left + (right - left) / 2;
        
        // sorting first and secound half
        sortArr(arr, left, mid);
        sortArr(arr, mid + 1, right);
        printArr(arr, left);
        printArr(arr, right);

        // merging array
        mergeArr(arr, left, mid, right);
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void mergeArr(int arr[], int left, int mid, int right)
{
    // size of temp left half arr = n1
    // size of temp right half arr = n2
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int i, j, k;

    // Create 2 temp arr
    int l[n1], r[n2];

    // copy data in temp array for modification
    for (i = 0; i < n1; i++)
        l[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        r[j] = arr[mid + 1 + j];

    // Merge elemrnt from temp array in main array
    i = j = 0; // initial iindex of 1st and 2nd subarray
    k = left; // initial index of merged arrray
    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    
    // Copying the remanng elements if any into main array
    while (i < n1)
    {
        arr[k] = r [i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = r[j];
        k++;
        j++;
    }
    
    

}