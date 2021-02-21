#include "HashMap.h"

// 1. Two Sum
vector<int> HashMap::twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;  // <num, index>
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int delta = target - nums[i];
        if (map.find(delta) != map.end()) {
            result.push_back(map[delta]);
            result.push_back(i);
        } else {
            map[nums[i]] = i; // map.insert(make_pair(nums[i], i));
        }
    }

    return result;
}

// 3. Longest Substring Without Repeating Characters
int HashMap::lengthOfLongestSubstring(string s) {
    int res = 0, left = 0;
    unordered_map<char, int> hashMap;
    for (int i = 0; i < s.size(); ++i) {
        if (hashMap.count(s[i]) && hashMap[s[i]] >= left)
            left = hashMap[s[i]] + 1;
        hashMap[s[i]] = i;
        res = max(res, i - left + 1);
    }

    return res;
}

/*
   int lengthOfLongestSubstring(string s) {
   vector<int> dict(256, -1);
   int maxLen = 0, start = -1;

   for (int i = 0; i != s.length(); i++) {
    if (dict[s[i]] > start)
        start = dict[s[i]];
    dict[s[i]] = i;
    maxLen     = max(maxLen, i - start);
   }

   return maxLen;
   }
 */

int HashMap::lengthOfLongestSubstringHashSet(string s) {
    int res = 0, left = 0;
    unordered_set<char> hashSet;
    for (int i = 0; i < s.size();) {
        if (hashSet.count(s[i]))
            hashSet.erase(s[left++]);
        else {
            hashSet.insert(s[i++]);
            res = max(res, (int)hashSet.size());
        }
    }

    return res;
}

int HashMap::lengthOfLongestSubstringFollowUp(string s, int k) {
    int res = 0, left = 0;
    unordered_map<char, queue<int>> hashMap;
    for (int i = 0; i < s.size(); ++i) {
        hashMap[s[i]].push(i);
        if (hashMap[s[i]].size() == k) {
            left = hashMap[s[i]].front() + 1; hashMap[s[i]].pop();
        }
        res = max(res, i - left + 1);
    }

    return res;
}

// 316. Remove Duplicate Letters
string HashMap::removeDuplicateLetters(string s) {
    int cnt[256] = { 0 };
    bool used[256] = { false };
    for (const auto& c: s)
        ++cnt[c];

    string res = "0";
    for (const auto& c: s) {
        --cnt[c];
        if (used[c])
            continue;

        while (c < res.back() && cnt[res.back()] > 0) {
            used[res.back()] = false;
            res.pop_back();
        }
        res += c;
        used[c] = true;
    }

    return res.substr(1);
}

// 128. Longest Consecutive Sequence
int HashMap::longestConsecutive(vector<int>& nums) {
    if (nums.empty())
        return 0;

    int res = 1;
    unordered_set<int> graph(nums.begin(), nums.end());
    for (auto& n : graph) {
        int pre = n - 1, next = n + 1;
        while (graph.count(pre)) {
            graph.erase(pre);
            --pre;
        }
        while (graph.count(next)) {
            graph.erase(next);
            ++next;
        }
        res = max(res, next - pre - 1);
    }

    return res;
}
