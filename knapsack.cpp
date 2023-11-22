#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double valuePerWeight;

    Item(int w, int v) : weight(w), value(v), valuePerWeight(static_cast<double>(v) / w) {}
};

bool compareItems(const Item& item1, const Item& item2) {
    return item1.valuePerWeight > item2.valuePerWeight;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    for (const Item& item : items) {
        if (capacity <= 0) {
            break;
        }

        int weightTaken = min(item.weight, capacity);
        totalValue += (weightTaken * item.valuePerWeight);
        capacity -= weightTaken;
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    vector<Item> items;
    for (int i = 0; i < n; i++) {
        int weight, value;
        cout << "Enter weight and value of item " << i + 1 << ": ";
        cin >> weight >> value;
        items.push_back(Item(weight, value));
    }

    double maxValue; // Declare maxValue outside the switch-case
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Calculate Maximum Value for Fractional Knapsack\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                maxValue = fractionalKnapsack(items, capacity);
                cout << "Maximum value that can be obtained: " << maxValue << endl;
                break;
            case 2:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
