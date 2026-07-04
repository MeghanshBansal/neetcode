class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> q;
        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && arr[q.back()] <= arr[i])
            {
                q.pop_back();
            }

            q.push_back(i);
        }

        vector<int> ans;
        ans.push_back(arr[q.front()]);

        int n = arr.size();
        for (int i = k; i < n; i++)
        {
            while (!q.empty() && q.front() < i - k + 1)
            {
                q.pop_front();
            }

            while (!q.empty() && arr[q.back()] <= arr[i])
            {
                q.pop_back();
            }

            q.push_back(i);
            ans.push_back(arr[q.front()]);
        }

        return ans; 
    }
};
