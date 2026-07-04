from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        kMostCommon = count.most_common(k)
        ans = []
        for v in kMostCommon:
            ans.append(v[0])
        return ans