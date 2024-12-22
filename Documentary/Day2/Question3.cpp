#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; // Handle empty array case

    int uniqueIndex = 0; // Pointer for the position of unique elements

    // Start from the second element and compare with the previous one
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[uniqueIndex]) {
            uniqueIndex++; // Move to the next unique position
            nums[uniqueIndex] = nums[i]; // Update the position with the new unique element
        }
    }

    // The number of unique elements is uniqueIndex + 1
    return uniqueIndex + 1;
}

int main() {
    vector<int> nums = {1, 1, 2}; // Example input
    int uniqueCount = removeDuplicates(nums);

    cout << "Number of unique elements: " << uniqueCount << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}