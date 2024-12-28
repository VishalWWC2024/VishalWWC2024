//Find the Town Judge (LeetCode)

#include <iostream>
#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
    // Create an array to track trust counts for each person
    vector<int> trustCount(n + 1, 0);  // trustCount[i] stores the trust score of person i
    
    // Process all trust relationships
    for (const auto& t : trust) {
        trustCount[t[0]]--;  // t[0] trusts someone, so decrement their score
        trustCount[t[1]]++;  // t[1] is trusted, so increment their score
    }
    
    // Find the person who satisfies the judge conditions
    for (int i = 1; i <= n; i++) {
        if (trustCount[i] == n - 1) { // Judge's trust score should be n-1
            return i;
        }
    }
    
    // If no judge found, return -1
    return -1;
}

int main() {
    vector<vector<int>> trust = {{1, 2}, {2, 3}, {4, 2}};
    int n = 4;
    cout << findJudge(n, trust); // Output: 2
    return 0;
}
