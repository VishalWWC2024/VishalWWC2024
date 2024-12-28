//Find the Kth Smallest Sum of Matrix with Sorted Rows

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Custom comparator for priority_queue
struct Compare {
    bool operator()(const pair<int, vector<int>>& a, const pair<int, vector<int>>& b) {
        return a.first > b.first; // Min-heap based on sum
    }
};

int kthSmallestSum(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, Compare> minHeap;

    int initialSum = 0;
    for (int i = 0; i < rows; i++) {
        initialSum += matrix[i][0];
    }
    minHeap.push({initialSum, vector<int>(rows, 0)});

    for (int count = 1; count < k; count++) {
        auto top = minHeap.top();
        minHeap.pop();
        int sum = top.first;
        vector<int> indices = top.second;

        for (int i = 0; i < rows; i++) {
            if (indices[i] + 1 < matrix[i].size()) {
                vector<int> newIndices = indices;
                newIndices[i]++;
                int newSum = sum - matrix[i][indices[i]] + matrix[i][newIndices[i]];
                minHeap.push({newSum, newIndices});
            }
        }
    }
    return minHeap.top().first;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 11}, {2, 4, 6}};
    int k = 5;
    cout << "The " << k << "th smallest sum is: " << kthSmallestSum(matrix, k) << endl;
    return 0;
}
