// Leetcode 865: Smallest Subtree with all the Deepest Nodes
// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/

// ****************************************************************
// TC: O(n)
// SC: O(h) where h is the height of the binary tree
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
class Solution {
public:
    TreeNode* dfs(TreeNode* root, int& depth) {
        if (!root) {
            depth = 0;
            return nullptr;
        }

        int leftDepth = 0, rightDepth = 0;
        TreeNode* leftNode = dfs(root->left, leftDepth);
        TreeNode* rightNode = dfs(root->right, rightDepth);

        if (leftDepth == rightDepth) {
            depth = leftDepth + 1;
            return root;
        } 
        else if (leftDepth > rightDepth) {
            depth = leftDepth + 1;
            return leftNode;
        } 
        else {
            depth = rightDepth + 1;
            return rightNode;
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth = 0;
        return dfs(root, depth);
    }
};
