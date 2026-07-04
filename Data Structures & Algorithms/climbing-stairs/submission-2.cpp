class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev2 = 1;  // Represents dp[i-2]
        int prev1 = 2;  // Represents dp[i-1]
        int current = 0;

        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2;  // dp[i] = dp[i-1] + dp[i-2]
            prev2 = prev1;            // Shift back 2 steps frame forward
            prev1 = current;          // Shift back 1 step frame forward
        }

        return prev1;
    }
};
