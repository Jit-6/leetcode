// Leetcode 1458: Max Dot Product of Two Subsequences
// https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/

// Recursion + Memoization
// ****************************************************************
// TC: O(n*m)
// SC: O(n*m)
// ****************************************************************
class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>&dp) {
        if(i >= nums1.size() || j >= nums2.size()) {
            return INT_MIN;
        }

        if(dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        //take 
        int take = nums1[i]*nums2[j];
        //akip 
        int skip = solve(i+1, j+1, nums1, nums2, dp);

        if(skip > 0) take += skip;
 
        int skip_i = solve(i+1, j, nums1, nums2, dp);
        int skip_j = solve(i, j+1, nums1, nums2, dp);
        
        return dp[i][j] =  max({take, skip_i, skip_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int ans = INT_MIN;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n, vector<int>(m,INT_MIN));
        return solve(0, 0, nums1, nums2, dp);
        
    }
};

// Bottom Up
// ****************************************************************
// TC: O(n*m)
// SC: O(n*m)
// ****************************************************************
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                int take = nums1[i] * nums2[j];
                if (dp[i + 1][j + 1] > 0)
                    take += dp[i + 1][j + 1];

                int skip_i = dp[i + 1][j];
                int skip_j = dp[i][j + 1];

                dp[i][j] = max({take, skip_i, skip_j});
            }
        }

        return dp[0][0];
    }
};

//Space Optimized Bottom Up
// ****************************************************************
// TC: O(n*m)
// SC: O(m) 
// ****************************************************************
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> next(m + 1, INT_MIN);
        vector<int> curr(m + 1, INT_MIN);

        for (int i = n - 1; i >= 0; i--) {
            curr[m] = INT_MIN;

            for (int j = m - 1; j >= 0; j--) {

                int take = nums1[i] * nums2[j];
                if (next[j + 1] > 0)
                    take += next[j + 1];

                int skip_i = next[j];
                int skip_j = curr[j + 1];

                curr[j] = max({take, skip_i, skip_j});
            }

            next = curr; 
        }

        return next[0];
    }
};
