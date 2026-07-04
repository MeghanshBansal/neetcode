class Solution:
    def largestRectangleArea(self, height: List[int]) -> int:
        n = len(height)
        def nearestLowLeft():
            left = []
            value = []
            index = []
            for i in range(n):
                if len(value) != 0 and value[-1] >= height[i]:
                    value.pop()
                    index.pop()
                    
                if len(value) == 0: 
                    left.append(-1) 
                else: 
                    left.append(index[-1])
                    
                value.append(height[i])
                index.append(i)
            return left 
        
        def nearestLowRight():
            right = []
            value = []
            index = []
            for i in range(n-1, -1, -1):
                if len(value) != 0 and value[-1] >= height[i]:
                    value.pop()
                    index.pop()
                    
                if len(value) == 0:
                    right.append(n)
                else: 
                    right.append(index[-1])
                    
                value.append(height[i])
                index.append(i)
            right.reverse()
            return right
        
        left = nearestLowLeft()
        right = nearestLowRight()
        
        maxArea = 0
        for i in range(n):
            area = (right[i] - left[i] - 1) * height[i]
            maxArea = max(maxArea, area)
        return maxArea