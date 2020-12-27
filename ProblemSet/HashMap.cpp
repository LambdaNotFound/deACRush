#include "HashMap.h"

// 3. Longest Substring Without Repeating Characters
int HashMap::lengthOfLongestSubstring(string s) {
    int res = 0, left = 0;
    unordered_map<int, int> hashMap;
    for (int i=0; i < s.size(); ++i) {
        if (hashMap.count(s[i]) && hashMap[s[i]] >= left)
            left = hashMap[s[i]] + 1;
        hashMap[s[i]] = i;
        res = max(res, i - left + 1);
    }

    return res;
}