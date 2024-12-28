//Inorder Traversal (Left, Root, Right)
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);  // Visit left subtree
    cout << root->val << " ";      // Visit root
    inorderTraversal(root->right); // Visit right subtree
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    inorderTraversal(root); // Output: 1 3 2
    return 0;
}
