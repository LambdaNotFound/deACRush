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
 * 126. Word Ladder II
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord.
 *
 * i. BFS
 * ii. Bidirectional BFS
 */
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);

public:
    vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string>& wordList);

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
