#include "BreadthFirstSearch.h"

#include "TreeNode.h"

// 126. Word Ladder II
vector<vector<string>> BreadthFirstSearch::findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord))
        return res;

    int level = 1, minLevel = INT_MAX;
    unordered_set<string> usedWords;
    queue<vector<string>> paths; paths.push({ beginWord });
    while (!paths.empty()) { // BFS
        vector<string> path = paths.front(); paths.pop();
        if (path.size() > level) {
            for (auto& word : usedWords)
                wordSet.erase(word);
            usedWords.clear();

            level = path.size();
            if (level > minLevel)
                break;
        }

        string word = path.back();
        for (int i = 0; i < beginWord.size(); ++i) {
            string nextWord = word;
            for (char j = 'a'; j <= 'z'; ++j) {
                if (nextWord[i] == j)
                    continue;
                else
                    nextWord[i] = j;

                if (wordSet.count(nextWord)) {
                    usedWords.insert(nextWord);

                    vector<string> nextPath = path;
                    nextPath.push_back(nextWord);
                    if (nextWord == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else
                        paths.push(nextPath);
                }
            }
        }
    }
    return res;
}

vector<vector<string>> BreadthFirstSearch::findLadders2(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord))
        return res;

    bool swapped = false, found = false;
    unordered_set<string> usedWords;
    vector<vector<string> > beginPaths{{ beginWord }};
    vector<vector<string> > endPaths{{ endWord }};
    while (!beginPaths.empty() && !endPaths.empty()) { // Bidirectional BFS
        if (beginPaths.size() > endPaths.size()) {
            swap(beginPaths, endPaths);
            swapped = !swapped;
        }

        for (int i = beginPaths.size(); i > 0; --i) {
            vector<string> path = beginPaths.front(); beginPaths.erase(beginPaths.begin());
            string word = path.front();
            for (int j = 0; j < beginWord.size(); ++j) {
                string nextWord = word;
                for (char k = 'a'; k <= 'z'; ++k) {
                    if (nextWord[j] == k)
                        continue;
                    else
                        nextWord[j] = k;

                    for (vector<string>& p : endPaths) {
                        if (p.front() == nextWord) {
                            found = true;
                            auto first = swapped ? p : path;
                            auto second = swapped ? path : p;

                            reverse(first.begin(), first.end());
                            first.insert(first.end(), second.begin(), second.end());
                            res.push_back(first);
                        }
                    }

                    if (wordSet.count(nextWord)) {
                        usedWords.insert(nextWord);

                        vector<string> nextPath = path;
                        nextPath.insert(nextPath.begin(), nextWord);
                        beginPaths.push_back(nextPath);
                    }
                }
            }
        }

        if (found)
            break;

        for (auto& word : usedWords)
            wordSet.erase(word);
        usedWords.clear();
    }

    return res;
}

// 226. Invert Binary Tree
TreeNode* BreadthFirstSearch::invertTree(TreeNode* root) {
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
