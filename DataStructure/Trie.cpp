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

// 211. Design Add and Search Words Data Structure
bool WordDictionary::searchHelper(const string& word, TrieNode* cur) {
    if (word.empty())
        return cur->endOfWord;
    else {
        char c = word[0];
        string next = word.substr(1);
        if (c == '.') {
            for (auto& p : cur->childNodeMap)
                if (searchHelper(next, p.second))
                    return true;
            return false;
        } else {
            if (!cur->childNodeMap.count(c))
                return false;
            cur = cur->childNodeMap[c];
            return searchHelper(next, cur);
        }
        return false;
    }
}

// 642. Design Search Autocomplete System
vector<string> AutocompleteSystem::input(char c) {
    if (c == '#') {
        addSentence(prefix, 1);
        prefix = "";
        return {};
    }
    prefix += c;

    TrieNode* cur = root;
    for (char& c : prefix) {
        if (!cur->childNodeMap.count(c))
            return {};
        cur = cur->childNodeMap[c];
    }

    auto cmp = [](pair<string, int>& a, pair<string, int>& b) {
               return a.second > b.second || (a.second == b.second && a.first < b.first);
           };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp) > q(cmp);
    for (auto& p : cur->wordFrequencyMap) {
        q.push(p);
        if (q.size() > k)
            q.pop();
    }

    vector<string> res(q.size());
    for (int i = q.size() - 1; i >= 0; --i) {
        res[i] = q.top().first; q.pop();
    }
    return res;
}
