//Preorder Traversal (Root, Left, Right)
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";     // Visit root
    preorderTraversal(root->left); // Visit left subtree
    preorderTraversal(root->right); // Visit right subtree
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    preorderTraversal(root); // Output: 1 2 3
    return 0;
}
