class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        for i in range(len(nums) - 2):
            if i == 0 or nums[i] != nums[i-1]:
                j = i+1
                k = len(nums) - 1
                target = 0 - nums[i]
                while j < k:
                    if nums[j] + nums[k] == target:
                        ans.append([nums[i], nums[j], nums[k]])
                        j+=1
                        k-=1
                        while j < k and nums[j] == nums[j-1]:
                            j+=1
                        while j < k and nums[k] == nums[k+1]:
                            k-=1

                    elif nums[j] + nums[k] < target:
                        j+=1
                    else: 
                        k-=1

        return ans 