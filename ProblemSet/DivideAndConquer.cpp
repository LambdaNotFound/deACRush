#include "DivideAndConquer.h"
#include "TreeNode.h"

// 95. Unique Binary Search Trees II
vector<TreeNode*> DivideAndConquer::generateTrees(int n) {
    unordered_map<string, vector<TreeNode*>> memo;
    return generateTreesHelper(1, n, memo);
}
vector<TreeNode*> DivideAndConquer::generateTreesHelper(int begin, int end, unordered_map<string, vector<TreeNode*>>& memo) {
    if (begin > end)
        return { nullptr };

    string key = to_string(begin) + '-' + to_string(end);
    if (memo.count(key))
        return memo[key];

    vector<TreeNode*> res;
    for (int i = begin; i <= end; ++i) {
        vector<TreeNode*> leftChild = generateTreesHelper(begin, i - 1, memo);
        vector<TreeNode*> rightChild = generateTreesHelper(i + 1, end, memo);
        for (TreeNode* left : leftChild)
            for (TreeNode* right : rightChild) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                res.push_back(root);
            }
    }

    memo[key] = res;
    return res;
}


// 169. Majority Element
int DivideAndConquer::majorityElement(vector<int>& nums) {
    return majorityElementHelper(nums, 0, (int)nums.size());
}
int DivideAndConquer::majorityElementHelper(vector<int>& nums, int left, int right) {
    if (left == right - 1)
        return nums[left];

    int mid = left + (right - left) / 2;
    int leftMajority = majorityElementHelper(nums, left, mid);
    int rightMajority = majorityElementHelper(nums, mid, right);

    if (leftMajority == rightMajority)
        return leftMajority;
    else {
        int leftMajorityCountInRight = count(nums, mid, right, leftMajority);
        int rightMajorityCountInLeft = count(nums, left, mid, rightMajority);

        if (leftMajorityCountInRight > rightMajorityCountInLeft)
            return leftMajority;
        else
            return rightMajority;
    }
}
int DivideAndConquer::count(vector<int>& nums, int left, int right, int target) {
    int count = 0;
    for (int i = left; i < right; ++i)
        if (nums[i] == target)
            ++count;
    return count;
}

// 241. Different Ways to Add Parentheses
vector<int> DivideAndConquer::diffWaysToCompute(string input) {
    unordered_map<string, vector<int>> memo;
    return diffWaysToComputeHelper(input, memo);
}
vector<int> DivideAndConquer::diffWaysToComputeHelper(const string& s, unordered_map<string, vector<int>>& memo) {
    if (memo.count(s))
        return memo[s];

    vector<int> res;
    for (int i = 0; i < s.size() - 1; ++i) {
        if (isdigit(s[i]))
            continue;

        vector<int> left = diffWaysToComputeHelper(s.substr(0, i), memo);
        vector<int> right = diffWaysToComputeHelper(s.substr(i + 1), memo);
        for (auto x : left)
            for (auto y : right)
                if (s[i] == '+')
                    res.push_back(x + y);
                else if (s[i] == '-')
                    res.push_back(x - y);
                else
                    res.push_back(x * y);
    }

    if (res.size() == 0)
        res.push_back(stoi(s));
    memo[s] = res;

    return res;
}
