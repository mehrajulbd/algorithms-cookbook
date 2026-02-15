#include <iostream>
using namespace std;

int num[100000], temp[100000];

// call mergesort(a, b) if you want to sort num[a...b]
void mergesort(int lo, int hi)
{
    if(lo == hi) return;
    int mid = (lo + hi)/2;

    cout << "Dividing:  [" << lo << "..." << hi << "] -> Left: [" 
         << lo << "..." << mid << "], Right: [" << mid + 1 << "..." << hi << "]" << endl;

    mergesort(lo, mid);
    mergesort(mid + 1, hi);

    int i, j, k;
    for(i = lo, j = mid + 1, k = lo; k <= hi; k++)
    {
        if(i == mid + 1) temp[k] = num[j++];
        else if(j == hi + 1) temp[k] = num[i++];
        else if(num[i] < num[j]) temp[k] = num[i++];
        else temp[k] = num[j++];
    }

    for(k = lo; k <= hi; k++) num[k] = temp[k];
    
    // --- STEP SHOW: Print merging action ---
    cout << "Merged [" << lo << "..." << hi << "]: ";
    for(int x = lo; x <= hi; x++) {
        cout << num[x] << " ";
    }
    cout << endl;
}

int main() 
{
    int n = 8; 
    
    int initial_values[] = {38, 27, 43, 3, 9, 82, 10, 19};
    for(int i = 0; i < n; i++) {
        num[i] = initial_values[i];
    }

    cout << "Initial Array: ";
    for(int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << "\n\n--- Starting Merge Sort ---\n\n";

    // Call the function from index 0 to n-1
    mergesort(0, n - 1);

    cout << "\n--- Merge Sort Complete ---\n\n";
    cout << "Final Sorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}