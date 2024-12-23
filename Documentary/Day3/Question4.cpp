#include <iostream>
using namespace std;

int findTheWinner(int n, int k) {
    int winner = 0; // Base case: when there's 1 friend, the winner is at index 0 (0-based indexing)
    for (int i = 2; i <= n; i++) {
        winner = (winner + k) % i;
    }
    return winner + 1; // Convert to 1-based indexing
}

int main() {
    int n = 5, k = 2; // Example input
    cout << "The winner is: Friend " << findTheWinner(n, k) << endl;
    return 0;
}
