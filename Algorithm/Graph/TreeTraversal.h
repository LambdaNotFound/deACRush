#ifndef ACRUSH_TREETRAVERSAL_H
#define ACRUSH_TREETRAVERSAL_H

#include "StandardLibrary.h"

using namespace std;

struct TreeNode;

class TreeTraversal {

/**
 * Iterative approach with a stack
 *
 * Iterative approach w/o a stack: Morris
 */

/*
 * 144. Binary Tree Preorder Traversal
 * [root, L, R]
 *
 * i. single stack
 */
public:
    vector<int> preorderTraversal(TreeNode* root);

public:
    vector<int> preorderTraversalMorris(TreeNode* root);

/*
 * 94. Binary Tree Inorder Traversal
 * [L, root, R]
 *
 * i. single stack
 * variant: with *pre pointer, useful when traverse Binary Search Tree
 */
public:
    vector<int> inorderTraversal(TreeNode* root);

public:
    vector<int> inorderTraversalMorris(TreeNode* root);

/*
 * 145. Binary Tree Postorder Traversal
 * [L, R, root]
 *
 * i. single stack w/ a pre pointer <= LIKE
 * ii. single stack
 */
public:
    vector<int> postorderTraversal(TreeNode* root); // keep root on stack

public:
    vector<int> postorderTraversal2(TreeNode* root); // insert

/*
 * 230. Kth Smallest Element in a BST
 *
 * Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine? <= store count of children in each node.
 *
 * i. BST InorderTraversal
 */
public:
    int kthSmallest(TreeNode* root, int k);
};

#endif //ACRUSH_TREETRAVERSAL_H
