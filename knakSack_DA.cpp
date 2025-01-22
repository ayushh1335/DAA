#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int profit;
    int weight;
};

void knapsack(int capacity, int n, Item items[]) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].profit + dp[i - 1][w - items[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum profit is: " << dp[n][capacity] << endl;

    // Trace back to find the selected items
    int w = capacity;
    cout << "Selected items: ";
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " "; // Item index
            w -= items[i - 1].weight;
        }
    }
    cout << endl;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];
    cout << "Enter the profit of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit;
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    knapsack(capacity, n, items);
    return 0;
}
