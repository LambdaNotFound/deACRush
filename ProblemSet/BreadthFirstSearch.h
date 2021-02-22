#ifndef ACRUSH_BREADTHFIRSTSEARCH_H
#define ACRUSH_BREADTHFIRSTSEARCH_H

#include "StandardLibrary.h"

using namespace std;

struct TreeNode;

struct Node;

class BreadthFirstSearch {

/**
 * Binary Tree BFS
 */

/*
 * 116. Populating Next Right Pointers in Each Node
 * 117. Populating Next Right Pointers in Each Node II
 */
public:
    Node* connect(Node* root);

/*
 * 17. Letter Combinations of a Phone Number
 *
 * i. Backtracking
 * ii. BFS
 */
public:
    vector<string> letterCombinations(string digits);

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

/*
 * 297. Serialize and Deserialize Binary Tree
 *
 * i. BFS
 * ii. DFS
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root);

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data);
};

};

#endif //ACRUSH_BREADTHFIRSTSEARCH_H
