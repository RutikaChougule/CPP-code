#include <iostream>
using namespace std;

long long int nonRecursiveFibonacci(int n) {
    if (n <= 1)
        return n;

    long long int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

long long int recursiveFibonacci(int n) {
    if (n <= 1)
        return n;
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int main() {
    int choice, n;

    do {
        cout << "Menu:\n";
        cout << "1. Calculate Fibonacci number (Non-recursive)\n";
        cout << "2. Calculate Fibonacci number (Recursive)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value of n: ";
                cin >> n;
                cout << "Fibonacci(" << n << ") = " << nonRecursiveFibonacci(n) << endl;
                break;

            case 2:
                cout << "Enter the value of n: ";
                cin >> n;
                cout << "Fibonacci(" << n << ") = " << recursiveFibonacci(n) << endl;
                break;

            case 3:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
