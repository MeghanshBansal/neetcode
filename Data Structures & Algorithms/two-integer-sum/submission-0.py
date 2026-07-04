class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dictionary = dict()
        for i in range(0, len(nums)):
            want = target - nums[i]
            if dictionary.get(want) != None:
                return [dictionary.get(want), i]
            dictionary[nums[i]] = i

        return [-1, -1]