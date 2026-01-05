// Leetcode: 66. Plus One
// https://leetcode.com/problems/plus-one/description

// ****************************************************************
// TC: O(n)
// SC: O(1)
// ****************************************************************

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n-1; i >= 0; i--) {
            if(digits[i] < 9) {
                // increase the digit by one
                digits[i]++;
                //return the digits array as there is no carry no need to traverse the remaining array
                return digits;
            }

            // If the digit is 9, adding one results in 10, which generates a carry.
            digits[i] = 0;
        }

        //if the loop is completed means all the digits are 9 , e.g- [9] so now it becomes [0] we have to insert 1 in the front of the array
        digits.insert(digits.begin(),1);

        return digits;
    }
};