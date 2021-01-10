#include "Backtracking.h"

// 46. Permutations
vector<vector<int> > Backtracking::permute(vector<int>& nums) {
    vector<vector<int> > res;
    vector<bool> visited(nums.size(), 0);
    vector<int> out;

    permuteHelper(nums, 0, visited, out, res);

    return res;
}
void Backtracking::permuteHelper(vector<int>& nums, int level, vector<bool>& visited, vector<int>& out, vector<vector<int> >& res) {
    if (level == nums.size()) {
        res.push_back(out);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i] == 1)
            continue;
        visited[i] = 1;
        out.push_back(nums[i]);
        permuteHelper(nums, level + 1, visited, out, res);
        out.pop_back();
        visited[i] = 0;
    }
}

vector<vector<int> > Backtracking::permuteBFS(vector<int>& nums) {
    vector<vector<int> > res;
    queue<vector<int> > q;
    q.push({ });

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = q.size() - 1; j >= 0; --j) {
            vector<int> cur = q.front(); q.pop();
            for (int k = 0; k <= cur.size(); ++k) {
                vector<int> tmp = cur;
                tmp.insert(tmp.begin() + k, nums[i]);
                q.push(tmp);
            }
        }
    }

    while (!q.empty()) {
        res.push_back(q.front()); q.pop();
    }

    return res;
}

vector<vector<int>> Backtracking::permuteSwap(vector<int>& nums) {
    vector<vector<int>> res;
    permuteSwapHelper(nums, 0, res);
    return res;
}
void Backtracking::permuteSwapHelper(vector<int>& nums, int start, vector<vector<int>>& res) {
    if (start == nums.size())
        res.push_back(nums);
    else {
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            permuteSwapHelper(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
}


// 47. Permutations II
vector<vector<int> > Backtracking::permuteUnique(vector<int>& nums) {
    vector<vector<int> > res;
    vector<bool> visited(nums.size(), 0);
    vector<int> out;

    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    permuteUniqueHelper(sortedNums, 0, visited, out, res);

    return res;
}
void Backtracking::permuteUniqueHelper(vector<int>& nums, int level, vector<bool>& visited, vector<int>& out, vector<vector<int> >& res) {
    if (level == nums.size()) {
        res.push_back(out);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i] == 1 || (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0))
            continue;
        visited[i] = 1;
        out.push_back(nums[i]);
        permuteUniqueHelper(nums, level + 1, visited, out, res);
        out.pop_back();
        visited[i] = 0;
    }
}
