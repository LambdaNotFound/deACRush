#include "Trie.h"

/** Inserts a word into the trie. */
void Trie::insert(string word) {
    TrieNode* cur = m_root;
    for (auto const& c : word) {
        if (!cur->findChild(c)) {
            TrieNode* tmp = new TrieNode(c);
            cur->addChild(tmp);
        }
        cur = cur->findChild(c);
    }
    cur->markEndOfWord();
}

/** Returns if the word is in the trie. */
bool Trie::search(string word) {
    TrieNode* cur = m_root;
    for (auto const& c: word) {
        cur = cur->findChild(c);
        if (!cur)
            return false;
    }
    return cur->isEndOfWord();
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool Trie::startsWith(string prefix) {
    TrieNode* cur = m_root;
    for (auto const& c: prefix) {
        cur = cur->findChild(c);
        if (!cur)
            return false;
    }
    return true;
}

/** follow-up: delete a word from the trie **/
bool Trie::deleteWord(string word) {
    TrieNode* cur = m_root;
    stack<TrieNode*> s;
    for (auto const& c: word) {
        cur = cur->findChild(c);
        if (!cur)
            return false;
        s.push(cur);
    }
    cur->unmarkEndOfWord();

    if (!cur->hasChild()) {
        while (!s.empty()) {
            TrieNode* tmp = s.top(); s.pop();
            tmp->removeChild(cur);
            cur = tmp;
            if (tmp->hasChild())
                break;
        }
    }

    return true;
}
