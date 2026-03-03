#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int id, start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity>& activities) {
    if (activities.empty()) return;

    // Sort activities by finish time
    sort(activities.begin(), activities.end(), compare);

    int lastSelected = 0, count = 1;
    
    cout << "Sorted Activities:\n";
    cout << "Activity " << activities[0].id << " [" << activities[0].start << ", " << activities[0].finish << "]\n";

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= activities[lastSelected].finish) {
            cout << "Activity " << activities[i].id << "[" << activities[i].start << ", " << activities[i].finish << "]\n";
            lastSelected = i;
            count++;
        }
    }

    cout << "Optimal Number of Activities: " << count << "\n";
}

int main() {
    vector<Activity> activities = {
        {1, 5, 9}, {2, 1, 2}, {3, 3, 4}, 
        {4, 0, 6}, {5, 5, 7}, {6, 8, 9}
    };

    activitySelection(activities);

    return 0;
}