class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set()
        for i in nums:
            st.add(i)

        maxL = 0
        for i in nums:
            curr = i + 1
            currL = 1
            while curr in st:
                curr = curr + 1
                currL += 1
            maxL = max(currL, maxL)
        return maxL

            