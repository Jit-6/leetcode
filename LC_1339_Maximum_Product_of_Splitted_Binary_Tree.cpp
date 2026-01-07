// Leetcode: 1339. Maximum Product of Splitted Binary Tree
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

// ****************************************************************
// TC: O(n)
// SC: O(h) where h is the height of the binary tree
// ****************************************************************

class Solution {
public:
    int mod = 1e9 + 7;

    void findTotalSum(TreeNode* root, int &sum) {
        if (!root) return;
        sum = ( sum + root->val)%mod;
        findTotalSum(root->left, sum);
        findTotalSum(root->right, sum);
    }

    int dfs(TreeNode* root, int &sum, long long &ans) {
        if (!root) return 0;

        int left = dfs(root->left, sum ,ans);
        int right = dfs(root->right, sum , ans);

        long long subSum = (root->val + left + right) % mod;

        ans = max(ans, subSum * (sum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        int sum = 0;
        findTotalSum(root, sum);

        long long ans = 0;
        dfs(root, sum, ans);

        return ans % mod;
    }
};
