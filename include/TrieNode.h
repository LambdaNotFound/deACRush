#ifndef ACRUSH_TRIENODE_H
#define ACRUSH_TRIENODE_H

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
    unordered_map<string, int> wordFrequencyMap; // autocomplete candidates
    string value; // Word Search II
};

#endif //ACRUSH_TRIENODE_H
