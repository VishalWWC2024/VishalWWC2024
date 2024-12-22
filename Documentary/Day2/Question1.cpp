#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to convert sorted array to height-balanced BST
TreeNode* sortedArrayToBST(const vector<int>& nums, int left, int right) {
    if (left > right) {
        return nullptr; // Base case: no elements to form a tree
    }

    // Choose the middle element as the root
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);

    // Recursively build the left and right subtrees
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);

    return root;
}

// Helper function to initiate the conversion
TreeNode* sortedArrayToBST(const vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

// Function to print the tree in-order (for testing purposes)
void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9}; // Example sorted array
    TreeNode* root = sortedArrayToBST(nums);

    cout << "In-order traversal of the constructed BST: ";
    inOrderTraversal(root); // Should print the sorted array
    cout << endl;

    return 0;
}