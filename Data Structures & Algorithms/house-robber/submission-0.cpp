class Solution {
   public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1 = 0;
        int current_max = 0;
        for (const int& num : nums) {
            current_max = max(num + prev2, prev1);
            prev2 = prev1;
            prev1 = current_max;
        }

        return prev1;
    }
};
