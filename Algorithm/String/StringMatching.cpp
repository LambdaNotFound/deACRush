#include "StringMatching.h"

// 28. Implement strStr()
int StringMatching::strStrBruteForce(string haystack, string needle) {
    if (needle.empty())
        return 0;

    int m = haystack.size(), n = needle.size();
    for (int offset = 0; offset < m; ++offset)
        for (int i = 0; i + offset < m && i < n; ++i) {
            if (haystack[offset + i] == needle[i]) {
                if (i == needle.size() - 1)
                    return offset;
            } else
                break;
        }

    return -1;
}

int StringMatching::strStr(string haystack, string needle) {
    vector<int> table = computeTable(needle); // Partial Match Table
    int m = haystack.size(), n = needle.size(), i = 0, j = 0;
    while (i < m && j < n) {
        if (haystack[i] == needle[j]) {
            ++i;
            ++j;
        } else
            j == 0 ? ++i : j = table[j - 1];
    }

    return j == n ? i - n : -1;
}
vector<int> StringMatching::computeTable(const string& needle) {
    int m = needle.size();
    vector<int> table(m, 0); // length of longest prefix that matches suffix
    for (int i = 0, j = 1; j < m; ) {
        if (needle[i] == needle[j]) {
            table[j] = i + 1; // length, index + 1, matching candidate
            ++i;
            ++j;
        } else
            i == 0 ? ++j : i = table[i - 1];
    }

    return table;
}

// 718. Maximum Length of Repeated Subarray
int StringMatching::findLengthBruteForce(vector<int>& A, vector<int>& B) {
    int m = A.size(), n = B.size(), res = 0;
    for (int offset = 0; offset < m; ++offset) {
        for (int i = offset, j = 0; i < m && j < n;) {
            int count = 0;
            while (i < m && j < n && A[i++] == B[j++])
                ++count;
            res = max(res, count);
        }
    }
    for (int offset = 0; offset < n; ++offset) {
        for (int i = 0, j = offset; i < m && j < n;) {
            int count = 0;
            while (i < m && j < n && A[i++] == B[j++])
                ++count;
            res = max(res, count);
        }
    }
    return res;
}

int findLengthBruteForce2(vector<int>& A, vector<int>& B) {
    int m = A.size(), n = B.size(), res = 0;
    for (int offsetA = 0; offsetA < m; ++offsetA) {
        for (int offsetB = 0; offsetA < m && offsetB < n; ++offsetB) {
            int i = offsetA, j = offsetB, count = 0;
            while (i < m && j < n && A[i++] == B[j++]) {
                ++count;
                res = max(res, count);
            }
        }
    }
    for (int offsetB = 0; offsetB < n; ++offsetB) {
        for (int offsetA = 0; offsetA < m && offsetB < n; ++offsetA) {
            int i = offsetA, j = offsetB, count = 0;
            while (i < m && j < n && A[i++] == B[j++]) {
                ++count;
                res = max(res, count);
            }
        }
    }
    return res;
}

int StringMatching::findLength(vector<int>& A, vector<int>& B) {
    return findLengthHelper(A, A.size() - 1, B, B.size() - 1, 0);
}
int StringMatching::findLengthHelper(vector<int>& A, int m, vector<int>& B, int n, int len) {
    if (m < 0 || n < 0)
        return len;

    int match = 0, unmatchA = 0, unmatchB = 0;
    if (A[m] == B[n])
        match = findLengthHelper(A, m - 1, B, n - 1, len + 1);
    unmatchA = findLengthHelper(A, m, B, n - 1, 0);
    unmatchB = findLengthHelper(A, m - 1, B, n, 0);

    int res = max(match, max(unmatchA, unmatchB));

    return max(len, res);
}

int StringMatching::findLengthDP(vector<int>& A, vector<int>& B) {
    int m = A.size(), n = B.size(), res = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = (A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : 0);
            res = max(res, dp[i][j]);
        }
    return res;
}

// 1143. Longest Common Subsequence
int StringMatching::longestCommonSubsequence(string A, string B) {
    return longestCommonSubsequenceHelper(A, A.size() - 1, B, B.size() - 1, 0);
}
int StringMatching::longestCommonSubsequenceHelper(string A, int m, string B, int n, int len) {
    if (m < 0 || n < 0)
        return len;

    int match = 0, unmatchA = 0, unmatchB = 0;
    if (A[m] == B[n])
        match = longestCommonSubsequenceHelper(A, m - 1, B, n - 1, len + 1);
    else {
        unmatchA = longestCommonSubsequenceHelper(A, m, B, n - 1, len);
        unmatchB = longestCommonSubsequenceHelper(A, m - 1, B, n, len);
    }

    int res = max(match, max(unmatchA, unmatchB));
    return max(len, res);
}

int StringMatching::longestCommonSubsequenceDP(string A, string B) {
    int m = A.size(), n = B.size(), res = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            res = max(res, dp[i][j]);
        }
    return res;
}
