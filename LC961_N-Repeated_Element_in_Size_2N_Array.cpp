// Leetcode 961 : N-Repeated Element in Size 2N Array
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array


// ****************************************************************
// Brute Force using an unordered_map
// TC: O(n)
// SC: O(n)
// ****************************************************************

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>mp;
        for(int i=0; i < n; i++) {
            if(++mp[nums[i]] == 2) {
                return nums[i];
            }

        }
        return -1;
    }
};


// ****************************************************************
// Observation based solution
// TC: O(n)
// SC: O(1)
// ****************************************************************

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i < n-2; i++) {
            if(nums[i] == nums[i+1] || nums[i] == nums[i+2]) {
                return nums[i];
            }

        }
        return nums[n-1];
    }
};