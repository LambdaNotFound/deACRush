#ifndef ACRUSH_TRIE_H
#define ACRUSH_TRIE_H

#include "StandardLibrary.h"

using namespace std;

class TrieNode {
public:
    TrieNode(const char c) : endOfWord(false) {
    }

    TrieNode() : TrieNode('\0') {
    }

    ~TrieNode() {
      for (auto const& [key, value] : childNodeMap)
        delete value;
    }

    bool isEndOfWord() const {
        return endOfWord;
    }

    bool hasChild() const {
        return childNodeMap.size() != 0;
    }

    TrieNode* findChild(const char c) {
        if (childNodeMap.count(c))
            return childNodeMap[c];
        else
            return nullptr;
    }

    void addChild(char c) {
        childNodeMap[c] = new TrieNode();
    }

    void removeChild(char c) {
        childNodeMap.erase(c);
    }

    void markEndOfWord() {
        endOfWord = true;
    }

    void unmarkEndOfWord() {
        endOfWord = false;
    }

private:
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

#endif //ACRUSH_TRIE_H
