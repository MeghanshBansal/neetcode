class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        def findMaxInK(start):
            maxEle = float('-inf')
            maxindex = -1
            for i in range(start, start + k):
                if maxEle < nums[i]: 
                    maxEle = nums[i]
                    maxindex = i
            return (maxEle, maxindex)
                
        maxValue = findMaxInK(0)
        ans = []
        ans.append(maxValue[0])
        
        for i in range(k, len(nums)):
            if maxValue != None and maxValue[1] < i -k + 1: 
                maxValue = None
            
            if maxValue == None:  
                maxValue = findMaxInK(i-k+1)
            else: 
                if nums[i] >= maxValue[0]:
                    maxValue = (nums[i], i)
            ans.append(maxValue[0])
        
        return ans