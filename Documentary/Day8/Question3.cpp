//Symmetric Tree (LeetCode)

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;  // Both are NULL
    if (!left || !right) return false; // One is NULL, the other isn't
    return (left->val == right->val) && 
           isMirror(left->left, right->right) && 
           isMirror(left->right, right->left); // Recursively check subtrees
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true; // An empty tree is symmetric
    return isMirror(root->left, root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << isSymmetric(root); // Output: 1 (true)
    return 0;
}
