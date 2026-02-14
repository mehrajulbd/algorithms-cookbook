#include <iostream>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// Function: merge
// Shows merging process step-by-step
// ------------------------------------------------------------
void merge(vector<int>& arr, int left, int mid, int right)
{
    cout << "\nMerging from index " << left << " to " << right << endl;

    int leftSize  = mid - left + 1;
    int rightSize = right - mid;

    vector<int> leftArr(leftSize);
    vector<int> rightArr(rightSize);

    // Copy data
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];

    for (int i = 0; i < rightSize; i++)
        rightArr[i] = arr[mid + 1 + i];

    cout << "Left Array:  ";
    for (int x : leftArr) cout << x << " ";

    cout << "\nRight Array: ";
    for (int x : rightArr) cout << x << " ";
    cout << endl;

    int i = 0, j = 0, k = left;

    // Merge process
    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            cout << "Placed " << leftArr[i] << " at index " << k << endl;
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            cout << "Placed " << rightArr[j] << " at index " << k << endl;
            j++;
        }
        k++;
    }

    // Remaining elements
    while (i < leftSize)
    {
        arr[k] = leftArr[i];
        cout << "Placed remaining " << leftArr[i] << " at index " << k << endl;
        i++;
        k++;
    }

    while (j < rightSize)
    {
        arr[k] = rightArr[j];
        cout << "Placed remaining " << rightArr[j] << " at index " << k << endl;
        j++;
        k++;
    }

    cout << "Array after merge: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// ------------------------------------------------------------
// Function: mergeSort
// Shows recursive calls
// ------------------------------------------------------------
void mergeSort(vector<int>& arr, int left, int right)
{
    cout << "\nmergeSort called for index range [" 
         << left << ", " << right << "]";

    if (left >= right)
    {
        cout << " → Single element, return\n";
        return;
    }

    cout << endl;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------
int main()
{
    vector<int> arr = {5, 2, 4, 1};

    cout << "Original Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "\nFinal Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
