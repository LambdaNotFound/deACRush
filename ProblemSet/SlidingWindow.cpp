#include "SlidingWindow.h"

vector<int> SlidingWindow::findAnagrams(string s, string p) {
    unordered_map<char, int> m;
    for (auto c: p)
        ++m[c];

    vector<int> res;
    for (int left = 0, right = 0, cnt = 0; right < s.size(); ++right) {
        if (m[s[right]]-- > 0)
            ++cnt;

        if (cnt == p.size())
            res.push_back(left);

        if (right - left + 1 == p.size() && m[s[left++]]++ >= 0)
            --cnt;
    }
    return res;
}
