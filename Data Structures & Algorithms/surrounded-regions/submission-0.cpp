class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if ((i==0 || i == rows -1 || j ==0 || j == cols -1) && board[i][j] == 'O')
                    dfs(i, j, board);
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j< cols; j++)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'R') board[i][j] = 'O';
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>> &board)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') return ;
        board[i][j] = 'R';
        dfs(i+1, j, board);
        dfs(i-1, j, board);
        dfs(i, j+1, board);
        dfs(i, j-1, board);
    }
};
