// Leetcode: 1390. Four Divisors
// https://leetcode.com/problems/four-divisors/description/


// ****************************************************************
// TC: O(n * sqrt(m)) where m is the maximum element in nums
// SC: O(1)
// ****************************************************************

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(int num : nums ) {

            int count = 0, sum = 0;

            for(int i=1; i*i <= num; i++) {
                if(num %i == 0 ) {
                    
                    if(i != num/i) {// not perfect square , i*i != num
                        count += 2;
                        sum += i+ (num/i);
                    }
                    else {
                        count++;
                        sum += i;
                    }
                }

                if(count > 4) {
                    break;
                }
            }
            if(count == 4) {
                ans += sum;
            }
        }
        return ans;
    }
};