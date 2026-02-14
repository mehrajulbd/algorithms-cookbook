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
// Function: insertionSort
// Purpose : Insertion Sort with step-by-step output and analysis
// ------------------------------------------------------------
void insertionSort(vector<int>& arr, long long& comparisons, long long& shifts)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        cout << "Pass " << i << ": ";

        while (j >= 0)
        {
            comparisons++;

            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                shifts++;
                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
        shifts++;

        printArray(arr);
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
    insertionSort(arr, comparisons, shifts);
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
