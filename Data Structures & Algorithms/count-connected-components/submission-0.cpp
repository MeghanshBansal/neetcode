class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (vector<int> &v: edges)
        {
            graph[v[0]].insert(v[1]);
            graph[v[1]].insert(v[0]);
        }

        int components = 0;
        unordered_set<int> visited;
        for (int i = 0; i < n; i++)
        {
            if (visited.find(i) == visited.end())
            {
                ++components;
                bfs(graph, i, visited);
            }
        }
        return components;
    }

    void bfs(unordered_map<int, unordered_set<int>> &graph, int start, unordered_set<int> &visited)
    {
        queue<pair<int, int>> q;
        q.push({start, -1});
        visited.insert(start);

        while (!q.empty())
        {
            auto &[node, parent] = q.front();
            q.pop();

            for (int child: graph[node])
            {
                if (child == node) continue;
                if (visited.find(child) == visited.end())
                {
                    visited.insert(child);
                    q.push({child, node});
                }
            }
        }
    }
};
