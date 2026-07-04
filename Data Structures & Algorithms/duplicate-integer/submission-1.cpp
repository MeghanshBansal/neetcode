class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int i: nums)
        {
            st.insert(i);
        }

        return st.size() != nums.size();
    }
};