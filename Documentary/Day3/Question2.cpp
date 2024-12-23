#include <iostream>
using namespace std;

int lastRemaining(int n) {
    int start = 1;      // Start of the range
    int step = 1;       // Step size
    bool leftToRight = true; // Direction of elimination
    int remaining = n;  // Numbers left in the range

    while (remaining > 1) {
        if (leftToRight || remaining % 2 == 1) {
            start += step; // Update start
        }
        step *= 2;          // Double the step
        remaining /= 2;     // Halve the remaining count
        leftToRight = !leftToRight; // Switch direction
    }

    return start; // The last remaining number
}

int main() {
    int n = 9; // Example input
    cout << "The last remaining number is: " << lastRemaining(n) << endl;
    return 0;
}
