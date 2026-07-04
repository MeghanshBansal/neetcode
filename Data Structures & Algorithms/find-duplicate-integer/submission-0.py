class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        seen = [False for i in range(len(nums))]

        for i in nums: 
            if seen[i-1] != False: 
                return i
            else: 
                seen[i-1] = True
        
        return -1