#include <iostream>
#include <vector>

using namespace std;

void findMaxSubarray(const vector<int>& arr) {
    if (arr.empty()) return;

    int max_so_far = arr[0];
    int current_max = arr[0];
    int start = 0, end = 0, temp_start = 0;

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > current_max + arr[i]) {
            current_max = arr[i];
            temp_start = i;
        } else {
            current_max += arr[i];
        }

        if (current_max > max_so_far) {
            max_so_far = current_max;
            start = temp_start;
            end = i;
        }
    }

    cout << "Max Subarray Sum: " << max_so_far << "\n";
    cout << "Indices         : [" << start << " to " << end << "]\n";
    cout << "Subarray Elements:[ ";
    for (int i = start; i <= end; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]\n\n";
}

int main() {
    findMaxSubarray({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    findMaxSubarray({-8, -3, -6, -2, -5, -4});
    findMaxSubarray({1, 2, 3, 4, 5});

    return 0;
}