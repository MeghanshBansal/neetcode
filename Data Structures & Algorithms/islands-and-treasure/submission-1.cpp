class Solution {
public:
    const int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.size() == 0) return ;

        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 0) 
                {
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0}; // Change in row
        int dc[] = {0, 0, -1, 1}; // Change in col

        while (!q.empty())
        {
            auto current = q.front();
            q.pop();

            int r = current.first;
            int c = current.second;

            for (int i = 0; i < 4; i++)
            {
                int new_r = r + dr[i];
                int new_c = c + dc[i];

                if (new_r < 0 || new_r >= ROWS || new_c < 0 || new_c >= COLS) continue;
                if (grid[new_r][new_c] == -1 || grid[new_r][new_c] != INF) continue;

                grid[new_r][new_c] = grid[r][c] + 1;
                q.push({new_r, new_c});
            }
        }
    }
};
