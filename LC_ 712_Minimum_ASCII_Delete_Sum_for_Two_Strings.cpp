// Leetcode 712: Minimum ASCII Delete Sum for Two Strings
// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

// Recursion + Memoization
// ****************************************************************
// TC: O(m*n)
// SC: O(m*n)
// ****************************************************************
class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        int m = s1.size();
        int n = s2.size();
        
        if (i >= m && j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i >= m)
            return dp[i][j] = s2[j] + solve(s1, s2, i, j + 1, dp);

        if (j >= n)
            return dp[i][j] = s1[i] + solve(s1, s2, i + 1, j, dp);

        if (s1[i] == s2[j])
            return dp[i][j] = solve(s1, s2, i + 1, j + 1, dp);

        int skip_i = s1[i] + solve(s1, s2, i + 1, j, dp);
        int skip_j = s2[j] + solve(s1, s2, i, j + 1, dp);

        return dp[i][j] = min(skip_i, skip_j);
    }

    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(s1, s2, 0, 0, dp);
    }
};

// Bottom Up
// ****************************************************************
// TC: O(m*n)
// SC: O(m*n)
// ****************************************************************
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int j = n - 1; j >= 0; j--) {
            dp[m][j] = s2[j] + dp[m][j + 1];
        }

        for (int i = m - 1; i >= 0; i--) {
            dp[i][n] = s1[i] + dp[i + 1][n];
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int skip_i = s1[i] + dp[i + 1][j];
                    int skip_j = s2[j] + dp[i][j + 1];
                    dp[i][j] = min(skip_i, skip_j);
                }
            }
        }

        return dp[0][0];
    }
};
