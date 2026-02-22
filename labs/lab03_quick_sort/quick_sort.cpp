#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

// ------------------------------------------------------------
// Function: printArray
// Purpose : Print array elements
// ------------------------------------------------------------
void printArray(const vector<int>& arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// ------------------------------------------------------------
// Function: partition
// Purpose : Partition function for Quick Sort
// ------------------------------------------------------------
int partition(vector<int>& arr, int p, int q,
              long long& comparisons, long long& swaps)
{
    int pivot = arr[p];   // x ← A[p]
    int i = p;            // i ← p

    cout << "Pivot = " << pivot << endl;

    for (int j = p + 1; j <= q; j++)   // for j ← p+1 to q
    {
        comparisons++;

        if (arr[j] <= pivot)           // if A[j] ≤ x
        {
            i++;
            swap(arr[i], arr[j]);      // exchange A[i] ↔ A[j]
            swaps++;

            cout << "  Swap: ";
            printArray(arr);
        }
    }

    swap(arr[p], arr[i]);              // exchange A[p] ↔ A[i]
    swaps++;

    cout << "  Pivot placed: ";
    printArray(arr);

    return i;                           // return i
}


// ------------------------------------------------------------
// Function: quickSort
// Purpose : Quick Sort with step-by-step output and analysis
// ------------------------------------------------------------
void quickSort(vector<int>& arr, int p, int q,
               long long& comparisons, long long& swaps)
{
    if (p < q)
    {
        cout << "\nQuickSort on range [" << p << ", " << q << "]\n";

        int r = partition(arr, p, q, comparisons, swaps);

        quickSort(arr, p, r - 1, comparisons, swaps);
        quickSort(arr, r + 1, q, comparisons, swaps);
    }
}


// ------------------------------------------------------------
// Function: readInput
// Purpose : Read numbers from file or console
// ------------------------------------------------------------
vector<int> readInput(bool readFromFile)
{
    vector<int> data;

    if (readFromFile)
    {
        ifstream file("test_cases.txt");
        if (!file)
        {
            cout << "Error opening file!\n";
            return data;
        }

        int value;
        while (file >> value)
        {
            data.push_back(value);
        }

        file.close();
    }
    else
    {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;

        data.resize(n);
        cout << "Enter " << n << " numbers:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> data[i];
        }
    }

    return data;
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------
int main()
{
    bool readFromFile = true;  // true = file, false = console

    vector<int> arr = readInput(readFromFile);

    if (arr.empty())
    {
        cout << "No data to sort.\n";
        return 0;
    }

    long long comparisons = 0;
    long long shifts = 0;

    cout << "Initial Array:\n";
    printArray(arr);

    clock_t start = clock();
    quickSort(arr, 0, arr.size() - 1, comparisons, shifts);
    clock_t end = clock();

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nFinal Sorted Array:\n";
    printArray(arr);

    cout << "\nAnalysis:\n";
    cout << "Comparisons: " << comparisons << endl;
    cout << "Shifts     : " << shifts << endl;
    cout << "Time Taken : " << timeTaken << " seconds\n";

    return 0;
}
