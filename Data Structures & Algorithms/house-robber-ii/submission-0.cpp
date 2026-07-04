class Solution {
   public:
    int helper(const vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        int current = 0;
        for (int i = start; i <= end; ++i) {
            current = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }

    int find_max(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int from_start = helper(nums, 0, n - 2);
        int to_end = helper(nums, 1, n - 1);
        return max(from_start, to_end);
    }

    int rob(vector<int>& nums) {
        return find_max(nums);
    }
};
