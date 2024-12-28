//Postorder Traversal (Left, Right, Root)
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);  // Visit left subtree
    postorderTraversal(root->right); // Visit right subtree
    cout << root->val << " ";        // Visit root
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    
    postorderTraversal(root); // Output: 3 2 1
    return 0;
}
