#ifndef ACRUSH_TRIE_H
#define ACRUSH_TRIE_H

#include "StandardLibrary.h"

using namespace std;

struct TrieNode {
    TrieNode() : endOfWord(false) {
    }

    ~TrieNode() {
      for (auto const& [key, value] : childNodeMap)
        delete value;
    }

    void addChild(char c) {
        childNodeMap[c] = new TrieNode();
    }

    void removeChild(char c) {
        childNodeMap.erase(c);
    }

    bool hasChild() const {
        return !childNodeMap.empty();
    }

    TrieNode* findChild(const char c) {
        auto it = childNodeMap.find(c);
        if (it != childNodeMap.end())
            return it->second;
        else
            return nullptr;
    }

    bool endOfWord;
    unordered_map<char, TrieNode*> childNodeMap;
};

/*
 * 208. Implement Trie (Prefix Tree)
 */
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word);

    /** Returns if the word is in the trie. */
    bool search(string word);

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix);

    /** follow-up: delete a word from the trie */
    bool deleteWord(string word);

private:
    TrieNode* root;
    // unique_ptr<TrieNode> root;
};

/*
 * 211. Design Add and Search Words Data Structure
 */
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TreeNode();
    }

    ~WordDictionary() {
        delete root;
    }

    void addWord(string word) {
        TreeNode* cur = root;
        for (char c : word) {
            if (!cur->childNodeMap.count(c))
                cur->childNodeMap[c] = new TreeNode();
            cur = cur->childNodeMap[c];
        }
        cur->word = word;
    }

    bool search(string word) {
        return searchHelper(word, root);
    }

private:
    struct TreeNode {
        TreeNode() {
        }

        ~TreeNode() {
            for (auto& p : childNodeMap)
                delete p.second;
        }

        unordered_map<char, TreeNode*> childNodeMap;
        string word;
    };

    bool searchHelper(string& word, TreeNode* cur) {
        if (word.empty() && !cur->word.empty())
            return true;
        else {
            for (int i = 0; i < word.size(); ++i) {
                char c = word[i];
                string next = word.substr(i);
                if (c != '.') {
                    if (!cur->childNodeMap.count(c))
                        return false;
                    cur->childNodeMap.count(c);
                    searchHelper(next, cur);
                } else {
                    for (auto& p : cur->childNodeMap) {
                        if (searchHelper(next, p.second))
                            return true;
                    }
                }
            }
        }
        return false;
    }

    TreeNode* root;
};

#endif //ACRUSH_TRIE_H
