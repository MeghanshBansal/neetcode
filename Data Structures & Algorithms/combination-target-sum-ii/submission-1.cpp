class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ans;
        solve(0, candidates, target, {}, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    void solve(int index, vector<int> &candidates, int target, vector<int> curr, set<vector<int>> &ans)
    {
        if (target == 0) ans.insert(curr);
        if (index == candidates.size() || target < 0) return ;
        
        curr.push_back(candidates[index]);
        solve(index + 1, candidates, target - candidates[index], curr, ans);
        curr.pop_back();
        solve(index + 1, candidates, target, curr, ans);
    }
};
