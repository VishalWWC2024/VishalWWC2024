#include <iostream>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

// Function for modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int minNonZeroProduct(int p) {
    long long maxNum = (1LL << p) - 1; // 2^p - 1
    long long pairProduct = modExp(maxNum - 1, maxNum / 2, MOD); // (2^p - 2)^(2^(p-1) - 1)
    return (pairProduct * (maxNum % MOD)) % MOD;
}

int main() {
    int p = 3; // Example input
    cout << "Minimum Non-Zero Product: " << minNonZeroProduct(p) << endl;
    return 0;
}
