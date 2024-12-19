#include <iostream>
using namespace std;

int main() {
    int N, sum;

    // Input N
    cout << "Enter a positive number: ";
    cin >> N;

    // Calculate sum using the formula
    sum = (N * (N + 1)) / 2;

    // Output the result
    cout << "The sum of natural numbers up to " << N << " is " << sum << endl;

    return 0;
}
