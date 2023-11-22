#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
    double ratio;  // Value-to-weight ratio
};

// Node in the branch and bound tree
struct Node {
    int level;       // Level in the tree (item index)
    int value;       // Total value at this node
    int weight;      // Total weight at this node
    double bound;    // Upper bound on the maximum value

    Node(int level, int value, int weight, double bound) : level(level), value(value), weight(weight), bound(bound) {}
};

// Comparator for sorting items by value-to-weight ratio in descending order
bool compareItems(const Item& item1, const Item& item2) {
    return item1.ratio > item2.ratio;
}

// Function to calculate the bound for a given node
double calculateBound(int n, int capacity, const vector<Item>& items, Node node) {
    if (node.weight >= capacity) {
        return 0;  // Node is infeasible, so bound is 0
    }
    
    double bound = node.value;  // Start with the value obtained so far
    
    int level = node.level + 1;
    int weight = node.weight;
    
    // Keep adding items to the knapsack until it's full
    while (level < n && weight + items[level].weight <= capacity) {
        bound += items[level].value;
        weight += items[level].weight;
        level++;
    }
    
    // If the knapsack is still not full, add a fraction of the next item
    if (level < n) {
        bound += (capacity - weight) * items[level].ratio;
    }
    
    return bound;
}

// Branch and bound algorithm to solve the 0-1 Knapsack problem
int branchAndBound(int n, int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compareItems);
    
    vector<Node> priorityQueue;
    priorityQueue.push_back(Node(-1, 0, 0, calculateBound(n, capacity, items, Node(-1, 0, 0, 0))));
    
    int maxProfit = 0;
    
    while (!priorityQueue.empty()) {
        Node node = priorityQueue.back();
        priorityQueue.pop_back();
        
        int level = node.level + 1;
        int value = node.value;
        int weight = node.weight;
        
        // Include the next item
        if (level < n) {
            if (weight + items[level].weight <= capacity) {
                maxProfit = max(maxProfit, value + items[level].value);
                priorityQueue.push_back(Node(level, value + items[level].value, weight + items[level].weight, node.bound));
            }
            
            // Calculate the bound for the node without including the next item
            double bound = calculateBound(n, capacity, items, Node(level, value, weight, node.bound));
            
            // Only explore the node if it has the potential to improve the best solution
            if (bound > maxProfit) {
                priorityQueue.push_back(Node(level, value, weight, bound));
            }
        }
    }
    
    return maxProfit;
}

int main() {
    int n, capacity;
    vector<Item> items;
    
    while (true) {
        int choice;
        cout << "Menu:\n";
        cout << "1. Enter the number of items and knapsack capacity\n";
        cout << "2. Enter item details\n";
        cout << "3. Solve the 0-1 Knapsack problem\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of items: ";
                cin >> n;
                cout << "Enter the knapsack capacity: ";
                cin >> capacity;
                items.clear();
                break;

            case 2:
                items.resize(n);
                for (int i = 0; i < n; i++) {
                    cout << "Enter the weight and value of item " << i + 1 << ": ";
                    cin >> items[i].weight >> items[i].value;
                    items[i].ratio = static_cast<double>(items[i].value) / items[i].weight;
                }
                break;

            case 3:
                if (n == 0 || capacity == 0 || items.empty()) {
                    cout << "Please enter item details and knapsack capacity first.\n";
                } else {
                    int maxProfit = branchAndBound(n, capacity, items);
                    cout << "The maximum value that can be obtained is: " << maxProfit << endl;
                }
                break;

            case 4:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please select a valid option from the menu.\n";
        }
    }

    return 0;
}
