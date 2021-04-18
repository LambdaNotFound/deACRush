#ifndef ACRUSH_WARGAME_H
#define ACRUSH_WARGAME_H

#include "StandardLibrary.h"

using namespace std;

vector<string> split(string s /* str */, string t /* token */) {
    vector<string> res;

    while (!s.empty()) {
        int idx = s.find(t);
        if (idx != string::npos) {
            string tmp = s.substr(0, idx);
            if (!tmp.empty())
                res.push_back(tmp);
            s = s.substr(idx + t.size());
        } else {
            res.push_back(s);
            s = "";
        }
    }

    return res;
}

vector<string> findContiguousHistory(vector<string>& s1, vector<string>& s2) {
    vector<string> res;
    int len = INT_MIN, m = s1.size(), n = s2.size();
    for (int offsetA = 0; offsetA < m; ++offsetA) {
        for (int offsetB = 0; offsetA < m && offsetB < n; ++offsetB) {
            int i = offsetA, j = offsetB;
            while (i < m && j < n && s1[i++] == s2[j++]) {
                if (len < i - offsetA + 1) {
                    len = i - offsetA + 1;
                    res = { s1.begin() + offsetA, s1.begin() + i };
                }
            }
        }
    }
    for (int offsetB = 0; offsetB < n; ++offsetB) {
        for (int offsetA = 0; offsetA < m && offsetB < n; ++offsetA) {
            int i = offsetB, j = offsetA;
            while (i < m && j < n && s2[i++] == s1[j++]) {
                if (len < i - offsetB + 1) {
                    len = i - offsetB + 1;
                    res = { s2.begin() + offsetB, s2.begin() + i };
                }
            }
        }
    }

    return res;
}

void buildAdjList(const vector<pair<int, int>>& edges, vector<vector<int>>& adjList) {
    for (auto& e : edges) {
        adjList[e.first].push_back(e.second);
    }
}
void findSource(const vector<pair<int, int>>& edges, vector<int>& sourceNodes) {
    unordered_map<int, int> edgesIn;
    for (auto& e : edges) {
        ++edgesIn[e.second];

        if (!edgesIn.count(e.first))
            edgesIn[e.first] = 0;
    }

    for (auto& p : edgesIn) {
        if (p.second == 0)
            sourceNodes.push_back(p.first);
    }
}
bool hasCommonAncestor(const vector<pair<int, int>>& edges, int v1, int v2) {
    int size = 20;
    vector<vector<int>> adjList(size, vector<int>(0));
    buildAdjList(edges, adjList);

    vector<int> sourceNodes;
    findSource(edges, sourceNodes);

    for (auto& v : sourceNodes) {
        queue<int> q; q.push(v);
        unordered_set<int> visited; visited.insert(v);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto& n : adjList[cur]) {
                if (visited.count(n))
                    continue;
                visited.insert(n);
                q.push(n);
            }
        }

        if (visited.count(v1) && visited.count(v2))
            return true;
    }

    return false;
}

long long countSubsegments(vector<int> arr) {
    vector<int> prefixSum = arr;
    for (int i = 1; i < prefixSum.size(); ++i) {
        prefixSum[i] = arr[i] + prefixSum[i - 1]; // arr[i] + prefixSum[i - 1]
    }

    int n = arr.size();
    long long res = 0;
    for (int j = 1; j + 1 < n; ++j) {
        for (int i = 0; i < j; ++i) {
            int first = prefixSum[i], second = prefixSum[j] - prefixSum[i],
                third = prefixSum.back() - prefixSum[j];
            if (first <= second && second <= third)
                ++res;
        }
    }
    return res;
}

vector<vector<int>> mergeAccount(vector<vector<int>>& idToPhoneNumbers) {
    unordered_map<int, vector<int>> idToPhoneNumber;
    unordered_map<int, vector<int>> phoneNumberToId;
    map<int, bool> visited;
    for (auto& v : idToPhoneNumbers) {
        int id = v[0];
        visited[id] = false;
        for (int i = 1; i < v.size(); ++i) {
            int phoneNumber = v[i];
            idToPhoneNumber[id].push_back(phoneNumber);
            phoneNumberToId[phoneNumber].push_back(id);
        }
    }

    vector<vector<int>> res;
    for (auto& p : visited) { // <id, viisted>
        if (p.second == true)
            continue;

        queue<int> q; q.push(p.first);
        visited[p.first] = true;
        set<int> ids, numbers;
        while (!q.empty()) {
            int currId = q.front(); q.pop();
            ids.insert(currId);

            for (int phoneNumber : idToPhoneNumber[currId]) {
                numbers.insert(phoneNumber);
                for (int id : phoneNumberToId[phoneNumber]) {
                    if (visited[id] == false) {
                        visited[id] = true;
                        q.push(id);
                    }
                }
            }
        }
        res.push_back(vector<int>(ids.begin(), ids.end()));
        res.push_back(vector<int>(numbers.begin(), numbers.end()));
    }

    return res;
}

vector<vector<int>> compress(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; ) {
        int j = i, count = 0;
        while (j < n && nums[j] == nums[i]) {
            ++j;
            ++count;
        }
        res.push_back({nums[i], count});
        i = j;
    }
    return res;
}

vector<vector<int>> computeDotProduct(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        auto& a = A[i];
        auto& b = B[j];
        int product = a[0] * b[0];
        int count = min(a[1], b[1]);

        a[1] -= count;
        if (a[1] == 0)
            ++i;

        b[1] -= count;
        if (b[1] == 0)
            ++j;

        if (!res.empty() && res.back()[0] == product) {
            res.back()[1] += count;
        } else {
            res.push_back({ product, count });
        }

        /*
        if (res.empty() || res.back()[0] != product) {
            res.push_back({product, count});
        } else {
            res.back()[1] += count;
        }
         */
    }

    return res;
}

#endif //ACRUSH_WARGAME_H
