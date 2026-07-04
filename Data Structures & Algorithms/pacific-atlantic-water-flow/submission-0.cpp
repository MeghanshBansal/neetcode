class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        queue<pair<int, int>> pacific_queue;
        queue<pair<int, int>> atlantic_queue;
        unordered_set<string> pacific_visited;
        unordered_set<string> atlantic_visited;

        for (int i = 0; i < rows; i++)
        {
            pacific_queue.emplace(i, 0);
            pacific_visited.insert(to_string(i) + "->" + to_string(0));

            atlantic_queue.emplace(i, cols - 1);
            atlantic_visited.insert(to_string(i) + "->" + to_string(cols - 1));
        }

        for (int j = 0; j < cols; j++)
        {
            pacific_queue.emplace(0, j);
            pacific_visited.insert(to_string(0) + "->" + to_string(j));

            atlantic_queue.emplace(rows - 1, j);
            atlantic_visited.insert(to_string(rows - 1) + "->" + to_string(j));
        }

        bfs(pacific_queue, pacific_visited, rows, cols, heights);
        bfs(atlantic_queue, atlantic_visited, rows, cols, heights);

        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                string key = to_string(i) + "->" + to_string(j);
                if (pacific_visited.count(key) && atlantic_visited.count(key))
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans; 
    }

    void bfs(queue<pair<int, int>> &q, unordered_set<string> &visited, int &rows, int &cols, vector<vector<int>> &heights)
    {
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;
            
            for (int i = 0; i < 4; i++)
            {
                int new_r = r + dr[i], new_c = c + dc[i];
                string key = to_string(new_r) + "->" + to_string(new_c);
                if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols 
                && !visited.count(key) && heights[new_r][new_c] >= heights[r][c])
                {
                    visited.insert(key);
                    q.emplace(new_r, new_c);
                }
            }
        }
    }
};
