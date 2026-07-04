class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        solve(0, nums, target, {}, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    void solve(int index, vector<int> &nums, int target, vector<int> curr, set<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.insert(curr);
        }

        if (index == nums.size() || target < 0) return ;

        curr.push_back(nums[index]);
        solve(index, nums, target - nums[index], curr, ans);
        curr.pop_back();
        solve(index + 1, nums, target, curr, ans);
    }
};
