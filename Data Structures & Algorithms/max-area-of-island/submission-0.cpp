class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int max_area = 0;
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 1)
                {
                    int c = 0;
                    dfs(i, j, ROWS, COLS, grid, c);
                    max_area = max(max_area, c);
                }
            }
        }
        return max_area;
    }

    void dfs(int r, int c, int rows, int cols, vector<vector<int>>& grid, int &area)
    {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != 1)
            return; 
        
        area += 1;
        grid[r][c] = 2;

        dfs(r+1, c, rows, cols, grid, area);
        dfs(r-1, c, rows, cols, grid, area);
        dfs(r, c+1, rows, cols, grid, area);
        dfs(r, c-1, rows, cols, grid, area);
    }

};
