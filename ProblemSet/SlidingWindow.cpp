#include "SlidingWindow.h"

// 30. Substring with Concatenation of All Words
vector<int> SlidingWindow::findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if (s.empty() || words.empty())
        return res;

    unordered_map<string, int> wordCount;
    for (auto& w : words)
        ++wordCount[w];

    int wordLen = words[0].size(), totalCount = words.size();
    for (int i = 0; i < wordLen; ++i) {
        int cnt = totalCount;
        unordered_map<string, int> wordUnused = wordCount;
        for (int j = i; j + wordLen - 1 < s.size(); j += wordLen) {
            string cur = s.substr(j, wordLen);
            if (wordUnused[cur]-- > 0)
                --cnt;

            int startIndex = j - totalCount * wordLen;
            if (startIndex >= 0) {
                string left = s.substr(startIndex, wordLen);
                if (++wordUnused[left] > 0)
                    ++cnt;
            }

            if (cnt == 0)
                res.push_back(startIndex + wordLen);
        }
    }

    return res;
}

//  6. Minimum Window Substring
string SlidingWindow::minWindow(string s, string t) {
    unordered_map<char, int> charCount;
    for (auto& c : t)
        ++charCount[c];

    int start = 0, minStart = -1, minLen = INT_MAX, cnt = t.size();
    for (int i = 0; i < s.size(); ++i) {
        if (charCount[s[i]]-- > 0) {
            --cnt;
        }

        while (cnt == 0) {
            if (minLen > i - start + 1) {
                minStart = start;
                minLen = i - start + 1;
            }

            if (++charCount[s[start]] > 0) {
                ++cnt;
            }
            ++start;
        }
    }

    return minStart == -1 ? "" : s.substr(minStart, minLen);
}

// 438. Find All Anagrams in a String
vector<int> SlidingWindow::findAnagrams(string s, string p) {
    vector<int> res;

    unordered_map<char, int> charCount;
    for (auto& c : p)
        ++charCount[c];

    int start = 0, cnt = p.size();
    for (int i = 0; i < s.size(); ++i) {
        if (charCount[s[i]]-- > 0)
            --cnt;

        while (cnt == 0) {
            if (i - start + 1 == p.size())
                res.push_back(start);

            if (++charCount[s[start]] > 0)
                ++cnt;

            ++start;
        }
    }

    return res;
}

// 567. Permutation in String
bool SlidingWindow::checkInclusion(string s1, string s2) {
    unordered_map<char, int> charCount;
    for (auto& c : s1)
        ++charCount[c];

    int start = 0, cnt = s1.size();
    for (int i = 0; i < s2.size(); ++i) {
        if (charCount[s2[i]]-- > 0)
            --cnt;

        while (cnt == 0) {
            if (++charCount[s2[start]] > 0)
                ++cnt;

            if (i - start + 1 == s1.size())
                return true;

            ++start;
        }
    }

    return false;
}
