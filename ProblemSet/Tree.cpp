#include "Tree.h"

#include "TreeNode.h"

// 226. Invert Binary Tree
TreeNode* Tree::invertTree(TreeNode* root) {
    if (!root)
        return root;

    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front(); q.pop();

        TreeNode* leftChild = cur->left;
        if (leftChild)
            q.push(leftChild);

        TreeNode* rightChild = cur->right;
        if (rightChild)
            q.push(rightChild);

        cur->left = rightChild;
        cur->right = leftChild;
    }

    return root;
}

/*
TreeNode* invertTree(TreeNode* root) {
    if (!root)
        return NULL;
    TreeNode *tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
}
 */
