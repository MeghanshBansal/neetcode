class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<tuple<int, int>> st;
        vector<int> ans(n, 0);

        st.push(make_tuple(temperatures[n-1], n-1));

        for (int i = n -2; i >= 0; i--)
        {
            while (!st.empty() && temperatures[i] >= get<0>(st.top()))
            {
                st.pop();
            }

            if (st.empty())
            {
                ans[i] = 0;
            }
            else 
            {
                ans[i] = get<1>(st.top()) - i;
            }
            st.push(make_tuple(temperatures[i], i));
        }
        return ans;
    }
};
