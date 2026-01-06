// Leetcode: 1161. Maximum Level Sum of a Binary Tree
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

// ****************************************************************
// TC: O(n)
// SC: O(w) where w is the maximum width of the binary tree
// ****************************************************************

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        int maxSum = INT_MIN, maxSumLevel = 1;

        while(!q.empty()) {

            int len = q.size();
            int levelSum = 0;

            for(int i=0; i<len; i++) {
                TreeNode *temp = q.front();
                q.pop();

                levelSum += temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            if(levelSum > maxSum) {
                maxSumLevel = level;
                maxSum = levelSum;
            }
            level++;
        }

        return maxSumLevel;
    }
};