
// method to merge two sorted subarrays into one sorted array
class MergeSort {
public:    
void merge(int arr[], int left, int mid, int right) {
    // Calculate sizes of two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to hold the two subarrays
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = arr[mid + 1 + j];

    // Merge the two sorted subarrays into arr[left..right]
    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray, if any
    while (i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray, if any
    while (j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    // Free memory allocated for temporary arrays
    delete[] leftArray;
    delete[] rightArray;
 }

// method to recursively sort the array using merge sort algorithm
  void sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        sort(arr, left, mid);          // Sort the left half
        sort(arr, mid + 1, right);     // Sort the right half
        merge(arr, left, mid, right);  // Merge the sorted halves
    }
  }

};