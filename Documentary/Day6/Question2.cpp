//Search in 2D Matrix (LeetCode)

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Perform binary search on the matrix
    int low = 0, high = m * n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid overflow
        int midValue = matrix[mid / n][mid % n];  // Convert mid to 2D index
        
        if (midValue == target) {
            return true;  // Target found
        }
        else if (midValue < target) {
            low = mid + 1;  // Search the right half
        }
        else {
            high = mid - 1;  // Search the left half
        }
    }
    
    return false;  // Target not found
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    
    int target1 = 3;
    int target2 = 13;
    
    cout << searchMatrix(matrix, target1) << endl;  // Output: 1 (true)
    cout << searchMatrix(matrix, target2) << endl;  // Output: 0 (false)
    
    return 0;
}
