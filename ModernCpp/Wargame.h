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

void buildAdjencyList(const vector<pair<int, int>>& edges, vector<vector<int>>& adjencyList) {
    for (auto& p : edges) {
        adjencyList[p.first].push_back(p.second);
    }
}

void findSource(const vector<pair<int, int>>& edges, vector<int>& sourceNodes) {
    unordered_map<int, int> edgesIn;
    for (auto& p : edges) {
        ++edgesIn[p.second];

        if (!edgesIn.count(p.first))
            edgesIn[p.first] = 0;
    }

    for (auto& p : edgesIn) {
        if (p.second == 0)
            sourceNodes.push_back(p.first);
    }
}

bool hasCommonAncestor(const vector<pair<int, int>>& edges, int v1, int v2) {
    int size = 20;
    vector<vector<int>> adjencyList(size, vector<int>(0));
    buildAdjencyList(edges, adjencyList);

    vector<int> sourceNodes;
    findSource(edges, sourceNodes);

    for (auto& v : sourceNodes) {
        queue<int> q; q.push(v);
        unordered_set<int> visited; visited.insert(v);

        while (!q.empty()) {
            int current = q.front(); q.pop();
            for (auto& n : adjencyList[current]) {
                visited.insert(n);
                q.push(n);
            }
        }

        if (visited.count(v1) && visited.count(v2))
            return true;
    }

    return false;
}

#endif //ACRUSH_WARGAME_H
