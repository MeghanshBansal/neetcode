class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n-1) return false;
        unordered_map<int, unordered_set<int>> graph;
        for (vector<int> &v: edges)
        {
            graph[v[0]].insert(v[1]);
            graph[v[1]].insert(v[0]);
        }

        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({0, -1});
        visited.insert(0);

        while (!q.empty())
        {
            auto &[node, parent] = q.front();
            q.pop();

            for (int neighbour: graph[node]){
                if (neighbour == parent)
                {
                    continue;
                }

                if (visited.count(neighbour) != 0)
                {
                    return false;
                }

                visited.insert(neighbour);
                q.push({neighbour, node});
            }
        }

        return visited.size() == n;
    }
};
