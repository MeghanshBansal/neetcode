class Solution:
    def trap(self, height: List[int]) -> int:
        def maxLeft():
            left = [0 for _ in range(len(height))]
            for i in range(1, len(height)):
                left[i] = max(left[i-1], height[i-1])

            return left 
        
        def maxRight():
            right = [0 for _ in range(len(height))]
            for i in range(len(height) - 2, -1, -1):
                right[i] = max(right[i+1], height[i+1])
            return right
        
        left = maxLeft()
        right = maxRight()
        totalWater = 0
        for i in range(len(height)):
            water = min(left[i], right[i]) - height[i]
            totalWater += (water if water > 0 else 0)

        return totalWater