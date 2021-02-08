#include "DynamicProgramming.h"

// 10. Regular Expression Matching
bool DynamicProgramming::isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (j > 1 && p[j - 1] == '*')
                dp[i][j] = dp[i][j - 2] || // '*' Matches zero of the preceding element
                           (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]); // '*' Matches 1 preceding element
            else // p[j - 1] != '*'
                dp[i][j] = i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];

    return dp[m][n];
}

bool DynamicProgramming::isMatchOptimized(string s, string p) {
    int m = s.size(), n = p.size();
    vector<bool> dp(n + 1, false);
    for (int i = 0; i <= m; ++i) {
        bool aux = dp[0]; // aux stores dp[i - 1][j - 1]
        dp[0] = (i == 0 ? true : false);
        for (int j = 1; j <= n; ++j) {
            bool tmp = dp[j];
            if (j > 1 && p[j - 1] == '*')
                dp[j] = dp[j - 2] || // '*' Matches zero of the preceding element
                        (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[j]); // '*' Matches 1 preceding element
            else // p[j - 1] != '*'
                dp[j] = i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') && aux;
            aux = tmp;
        }
    }
    return dp[n];
}

bool DynamicProgramming::isMatchRecursive(string s, string p) {
    if (p.empty())
        return s.empty();
    else if (p.size() > 1 && p[1] == '*')
        return isMatchRecursive(s, p.substr(2)) || // '*' Matches zero of the preceding element
               (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatchRecursive(s.substr(1), p)); // '*' Matches 1 preceding element
    else { // p[1] != '*'
        return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatchRecursive(s.substr(1), p.substr(1));
    }
}

// 44. Wildcard Matching
bool DynamicProgramming::isWildcardMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;
    for (int j = 1; j <= n; ++j)
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];

    return dp[m][n];
}

bool DynamicProgramming::isWildcardMatchOptimized(string s, string p) {
    if (p.empty())
        return s.empty();

    int m = s.size(), n = p.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int j = 1; j <= n; ++j)
        if (p[j - 1] == '*')
            dp[j] = dp[j - 1];
    for (int i = 1; i <= m; ++i) {
        bool aux = (i == 1 ? true : false); // aux stores dp[i - 1][j - 1]
        for (int j = 1; j <= n; ++j) {
            bool tmp = dp[j];
            if (p[j - 1] == '*')
                dp[j] = dp[j] || dp[j - 1];
            else
                dp[j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && aux;
            aux = tmp;
        }
    }

    return dp[n];
}

bool DynamicProgramming::isWildcardMatchRecursive(string s, string p) {
    if (s.empty())
        return p.empty() || (p[0] == '*' && isWildcardMatchRecursive(s, p.substr(1)));
    else if (p.empty())
        return false;
    else if (s[0] == p[0] || p[0] == '?')
        return isWildcardMatchRecursive(s.substr(1), p.substr(1));
    else if (p[0] == '*')
        return isWildcardMatchRecursive(s.substr(1), p) || isWildcardMatchRecursive(s, p.substr(1)); // '*' Matches one or zeon of the preceding element
    else
        return false;
}

// 72. Edit Distance
int DynamicProgramming::minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;

    return dp[m][n];
}

int DynamicProgramming::minDistanceOptimized(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<int> dp(n + 1);
    for (int j = 0; j <= n; ++j)
        dp[j] = j;
    for (int i = 1; i <= m; ++i) {
        int aux = i - 1; // aux stores dp[i - 1, j - 1]
        dp[0] = i;
        for (int j = 1; j <= n; ++j) {
            int tmp = dp[j];
            if (word1[i - 1] == word2[j - 1])
                dp[j] = aux;
            else
                dp[j] = min(aux, min(dp[j], dp[j - 1])) + 1;
            aux = tmp;
        }
    }

    return dp[n];
}

// 70. Climbing Stairs
int DynamicProgramming::climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// optimized space
int DynamicProgramming::climbStairsOptimized(int n) {
    vector<int> dp(2, 0);
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int aux = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = aux;
    }
    return dp[1];
}
