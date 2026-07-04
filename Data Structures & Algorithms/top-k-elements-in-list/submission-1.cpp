class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (const int i: nums)
        {
            count[i]++;
        }

        vector<pair<int, int>> v;
        for (const auto &[key, value]: count)
        {
            v.push_back(make_pair(value, key));
        }

        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.first >= b.first;
        });

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(v[i].second);
        }

        return ans; 
    }
};
