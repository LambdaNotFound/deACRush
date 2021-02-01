#ifndef ACRUSH_TRIE_H
#define ACRUSH_TRIE_H

#include "StandardLibrary.h"

using namespace std;

class TrieNode {
public:
    TrieNode(const char c) : m_is_end_of_word(false) {
    }

    TrieNode() : TrieNode('\0') {
    }

    ~TrieNode() {
      for (auto const& [key, value] : m_child_node_map)
        delete value;
    }

    bool isEndOfWord() const {
        return m_is_end_of_word;
    }

    bool hasChild() const {
        return m_child_node_map.size() != 0;
    }

    TrieNode* findChild(const char c) {
        if (m_child_node_map.count(c))
            return m_child_node_map[c];
        else
            return nullptr;
    }

    void addChild(char c) {
        m_child_node_map[c] = new TrieNode();
    }

    void removeChild(char c) {
        m_child_node_map.erase(c);
    }

    void markEndOfWord() {
        m_is_end_of_word = true;
    }

    void unmarkEndOfWord() {
        m_is_end_of_word = false;
    }

private:
    bool m_is_end_of_word;
    unordered_map<char, TrieNode*> m_child_node_map;
};

/*
 * 208. Implement Trie (Prefix Tree)
 */
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        m_root = new TrieNode();
    }

    ~Trie() {
        delete m_root;
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
    TrieNode* m_root;
    // unique_ptr<TrieNode> m_root;
};

#endif //ACRUSH_TRIE_H
