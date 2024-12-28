//Find Target Indices After Sorting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end()); // Sort the array
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            result.push_back(i); // Store the indices of the target
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 5};
    int target = 2;
    vector<int> indices = targetIndices(nums, target);
    if (!indices.empty()) {
        cout << "Target indices: ";
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "Target not found." << endl;
    }
    return 0;
}
