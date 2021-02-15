#ifndef ACRUSH_TRIE_H
#define ACRUSH_TRIE_H

#include "StandardLibrary.h"
#include "TrieNode.h"

using namespace std;

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
        root = new TrieNode();
    }

    ~WordDictionary() {
        delete root;
    }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->childNodeMap.count(c))
                cur->childNodeMap[c] = new TrieNode();
            cur = cur->childNodeMap[c];
        }
        cur->endOfWord = true;
    }

    bool search(string word) {
        return searchHelper(word, root);
    }

private:
    bool searchHelper(const string& word, TrieNode* cur);

    TrieNode* root;
};

/*
 * 642. Design Search Autocomplete System
 *
 * i. Trie + Priority Queue
 */
class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        prefix = "";
        root = new TrieNode();
        k = 3;

        for (int i = 0; i < sentences.size(); ++i)
            addSentence(sentences[i], times[i]);
    }

    vector<string> input(char c);

private:
    void addSentence(const string& sentence, int times) {
        TrieNode* cur = root;
        for (const char& c : sentence) {
            if (!cur->childNodeMap.count(c))
                cur->childNodeMap[c] = new TrieNode();
            cur = cur->childNodeMap[c]; // move cur before add frequency

            if (!cur->wordFrequencyMap.count(sentence))
                cur->wordFrequencyMap[sentence] = 0;
            cur->wordFrequencyMap[sentence] += times;
        }
        cur->endOfWord = true;
    }

    int k;
    string prefix;
    TrieNode* root;
};

#endif //ACRUSH_TRIE_H
