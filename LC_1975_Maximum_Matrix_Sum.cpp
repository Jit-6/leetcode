//Leetcode: 1975. Maximum Matrix Sum
// https://leetcode.com/problems/maximum-matrix-sum/description/

// ****************************************************************
// TC: O(n^2)
// SC: O(1)
// ****************************************************************

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int mini = INT_MAX;
        int count = 0;
        int n = matrix.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] < 0) {
                    count++;
                    matrix[i][j] = abs(matrix[i][j]);
                }

                mini = min(mini, matrix[i][j]);
                sum += matrix[i][j];
            }
        }

        if(count %2 == 0) 
        return sum;

        return sum - 2*mini;
    }
};