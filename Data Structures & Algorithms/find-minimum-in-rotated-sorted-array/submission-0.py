class Solution:
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) -1 
        min_value = float('inf')
        while low <= high:
            mid = low + (high - low) // 2
            if nums[low] <= nums[mid] :
                min_value = min(min_value, nums[low])
                low = mid + 1
            else: 
                min_value = min(min_value, nums[mid])
                high = mid - 1 
                
        return min_value