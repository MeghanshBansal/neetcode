class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int islands = 0;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    dfs(i, j, ROWS, COLS, grid);
                }
            }
        }
        return islands;
    }

    void dfs(int r, int c, int rows, int cols, vector<vector<char>>& grid)
    {
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] != '1')
            return ;

        grid[r][c] = '2';

        dfs(r+1, c, rows, cols, grid);
        dfs(r-1, c, rows, cols, grid);
        dfs(r, c+1, rows, cols, grid);
        dfs(r, c-1, rows, cols, grid);
    }
};
