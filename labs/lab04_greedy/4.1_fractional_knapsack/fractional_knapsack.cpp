#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int id;
    double value;
    double weight;
};

bool compareRatio(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(double capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compareRatio);

    double totalValue = 0.0;

    for (const auto& item : items) {
        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.value * (capacity / item.weight);
            break; 
        }
    }

    return totalValue;
}

int main() {
    double capacity = 50.0;
    
    vector<Item> items = {
        {1, 60.0, 10.0},
        {2, 100.0, 20.0},
        {3, 120.0, 30.0}
    };

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value in the knapsack = " 
         << fixed << setprecision(2) << maxValue << "\n";

    return 0;
}