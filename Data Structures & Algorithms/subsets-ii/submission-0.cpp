class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        solve(0, nums, curr, ans);
        return ans; 
    }

    void solve(int index, vector<int> &nums, vector<int> curr, vector<vector<int>> &ans)
    {
        if (index == nums.size()) 
        {
            ans.push_back(curr);
            return ;
        }

        curr.push_back(nums[index]);
        solve(index + 1, nums, curr, ans);
        curr.pop_back();

        while (index < nums.size() - 1 && nums[index] == nums[index+1])
        {
            index+=1;
        }

        solve(index + 1, nums, curr, ans);
    }
};
