class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row, col;
        unordered_map<string, unordered_set<char>> box;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    string key = to_string(i / 3) + "->" + to_string(j / 3);
                    if ((row[i].count(board[i][j]) != 0) || 
                        col[j].count(board[i][j]) != 0 ||
                        box[key].count(board[i][j]) != 0
                    ){
                        return false;
                    }

                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    box[key].insert(board[i][j]);
                }
            }
        }

        return true; 
    }
};
