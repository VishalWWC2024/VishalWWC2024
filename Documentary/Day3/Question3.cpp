#include <iostream>
#include <vector>
using namespace std;

bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: Single element in subarray
    for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }

    // Fill the DP table for subarrays of length > 1
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        }
    }

    // Player 1 wins if the score difference is non-negative
    return dp[0][n-1] >= 0;
}

int main() {
    vector<int> nums = {1, 5, 2}; // Example input
    cout << (PredictTheWinner(nums) ? "Player 1 can win!" : "Player 2 will win!") << endl;
    return 0;
}
