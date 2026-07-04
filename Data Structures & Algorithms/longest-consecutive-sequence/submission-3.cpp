class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int i: nums)
        {
            st.insert(i);
        }

        int max_seq = 0;
        for (int i: nums)
        {
            int curr = i + 1;
            int l = 1;
            while(st.find(curr) != st.end())
            {
                curr = curr + 1;
                l++;
            }

            max_seq = max(l, max_seq);
        }
        return max_seq;
    }
};
