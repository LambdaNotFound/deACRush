#ifndef ACRUSH_TREE_H
#define ACRUSH_TREE_H

#include "StandardLibrary.h"

using namespace std;

struct TreeNode;

class Tree {

/**
 * Tree Traversal: BFS
 */

/*
 * 226. Invert Binary Tree
 *
 * i. BFS
 */
public:
    TreeNode* invertTree(TreeNode* root);

/**
 * Tree Traversal: DFS with a stack
 */

/**
 * Tree: Recursion
 */

/*
 * 100. Same Tree
 *
 * i. recursion
 * ii. serialize tree
 */
public:
    bool isSameTree(TreeNode* p, TreeNode* q);

public:
    bool isSameTreeSerialize(TreeNode* p, TreeNode* q);
private:
    ostringstream serializeTreePreorder(TreeNode* root);

/*
 * 572. Subtree of Another Tree
 *
 * i. recursion
 * ii. serialize tree
 */
public:
    bool isSubtree(TreeNode* s, TreeNode* t);

public:
    bool isSubtreeSerialize(TreeNode* s, TreeNode* t);
private:
    void isSubtreeSerializeHelper(TreeNode* node, ostringstream& os);
};

#endif //ACRUSH_TREE_H
