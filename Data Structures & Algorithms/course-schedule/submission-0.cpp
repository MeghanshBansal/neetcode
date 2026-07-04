class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, unordered_set<int>> graph;
        for (vector<int> pair : prerequisites)
        {
            int from = pair[1];
            int to = pair[0];
            graph[from].insert(to);
            inDegree[to]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int canComplete = 0;

        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            canComplete++;
            unordered_set<int> children = graph[parent];
            for (int child : children)
            {
                inDegree[child]--;
                if (inDegree[child] == 0)
                {
                    q.push(child);
                }
            }
        }

        return (canComplete == numCourses);
    }
};
