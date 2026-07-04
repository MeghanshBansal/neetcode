class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        i, j = 0, (rows * cols) - 1
        while i <= j:
            mid = i + (j-i) // 2
            row = int(mid // cols)
            col = int(mid % cols)

            if matrix[row][col] == target: 
                return True 
            elif matrix[row][col] < target:
                i+=1
            else: j-=1
        return False
