class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size(); 
        int COLS = board[0].size();

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (board[i][j] == word[0])
                {
                    unordered_set<string> visited;
                    if (dfs(i, j, ROWS, COLS, board, word, 0)) return true;
                }
            }
        }

        return false; 
    }

    bool dfs(int r, int c, int ROWS, int COLS, vector<vector<char>> &board, string word, int index)
    {
        if (index == word.length()) return true; 
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || (board[r][c] != word[index]) ) 
            return false; 
        
        char original_char = board[r][c];
        board[r][c] = '#';
    
        bool ans = dfs(r+1, c, ROWS, COLS, board, word, index+1) ||
        dfs(r, c+1, ROWS, COLS, board, word, index+1) ||
        dfs(r-1, c, ROWS, COLS, board, word, index+1) ||
        dfs(r, c-1, ROWS, COLS, board, word, index+1);

        board[r][c] = original_char;
        return ans; 
    }
};
