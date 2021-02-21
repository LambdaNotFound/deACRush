#ifndef ACRUSH_TREE_H
#define ACRUSH_TREE_H

#include "StandardLibrary.h"

using namespace std;

struct TreeNode;

class Tree {

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

/*
 * 129. Sum Root to Leaf Numbers
 */
public:
    int sumNumbers(TreeNode* root);
};

#endif //ACRUSH_TREE_H
