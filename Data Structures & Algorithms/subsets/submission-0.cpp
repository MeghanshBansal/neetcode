class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        solve_recursive(0, nums, ans, {});
        return ans; 
    }

    void solve_recursive(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> curr)
    {
        ans.push_back(curr);
        for (int i = index; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            solve_recursive(i + 1, nums, ans, curr);
            curr.pop_back();
        }
    }
};
