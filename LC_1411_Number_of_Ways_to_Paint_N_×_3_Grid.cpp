// Leetcode: 1411. Number of Ways to Paint N × 3 Grid
// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/

// ****************************************************************
// TC: O(n)
// SC: O(1)
// ****************************************************************

class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9 + 7;

        long aba = 6;  // patterns like R Y R
        long abc = 6;  // patterns like R Y G

        for (int i = 1; i < n; i++) {
            long newAba = (aba * 3 + abc * 2) % mod;
            long newAbc = (aba * 2 + abc * 2) % mod;

            aba = newAba;
            abc = newAbc;
        }

        return (aba + abc) % mod;
    }
};
