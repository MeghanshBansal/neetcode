class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> mp;
        for (auto item : prerequisites) {
            int from = item[1], to = item[0];
            mp[from].push_back(to);
            indegree[to]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while (!q.empty()) {
            int parent = q.front();
            q.pop();

            ans.push_back(parent);
            for (int child : mp[parent]) {
                indegree[child]--;
                if (indegree[child] == 0) q.push(child);
            }
        }
        if (ans.size() == numCourses) return ans;
        return {};
    }
};
