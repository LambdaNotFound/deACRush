#include "Trie.h"

/** Inserts a word into the trie. */
void Trie::insert(string word) {
    TrieNode* cur = root;
    for (auto const& c : word) {
        if (!cur->findChild(c))
            cur->addChild(c);
        cur = cur->findChild(c);
    }
    cur->endOfWord = true;
}

/** Returns if the word is in the trie. */
bool Trie::search(string word) {
    TrieNode* cur = root;
    for (auto const& c: word) {
        cur = cur->findChild(c);
        if (!cur)
            return false;
    }
    return cur->endOfWord == true;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool Trie::startsWith(string prefix) {
    TrieNode* cur = root;
    for (auto const& c: prefix) {
        cur = cur->findChild(c);
        if (!cur)
            return false;
    }
    return true;
}

/** follow-up: delete a word from the trie **/
bool Trie::deleteWord(string word) {
    TrieNode* cur = root;
    stack<TrieNode*> s;
    for (auto const& c: word) {
        s.push(cur);
        cur = cur->findChild(c);
        if (!cur)
            return false;
    }

    if (!cur->endOfWord)
        return false;
    cur->endOfWord = false; // soft delete

    if (!cur->hasChild()) {
        delete cur;
        for (int i = word.size() - 1; i >= 0; --i) {
            cur = s.top(); s.pop();
            cur->removeChild(word[i]);
            if (cur->hasChild())
                break;
        }
    }

    return true;
}
