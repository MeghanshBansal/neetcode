class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        num = [{} for _ in range(9)]

        for i in range(len(board)):
            for j in range(len(board[i])):
                c = board[i][j]
                if c != '.':
                    if c in num[i] and num[i][c][0] > 0:
                        return False
                    if c in num[j] and num[j][c][1] > 0:
                        return False
                    if c in num[i//3*3 + j//3] and num[i//3*3 + j//3][c][2] > 0:
                        return False

                    if c not in num[i]:
                        num[i][c] = [0, 0, 0]
                    if c not in num[j]:
                        num[j][c] = [0, 0, 0]
                    if c not in num[i//3*3 + j//3]:
                        num[i//3*3 + j//3][c] = [0, 0, 0]

                    num[i][c][0] += 1
                    num[j][c][1] += 1
                    num[i//3*3 + j//3][c][2] += 1
        
        return True