class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n, string(n, '.'));

        n_queen(0, board, ans);
        return ans; 
    }

    void n_queen(int row, vector<string> &board, vector<vector<string>> &ans)
    {
        if (row >= board.size()) 
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col++)
        {
            if (is_safe(row, col, board))
            {
                board[row][col] = 'Q';
                n_queen(row + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }

    bool is_safe(int row, int col, const vector<string> &board)
    {
        // checking the upper in the row
        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col] == 'Q') return false; 
        }

        // checking the upper left diag
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q') return false; 
        }

        // checking upper right diag
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
        {
            if (board[i][j] == 'Q') return false; 
        }

        return true; 
    }
};
