class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def works(k):
            tot_hours = sum([math.ceil(num / k) for num in piles])
            return h >= tot_hours

        l = 1
        r = 1

        while not works(r):
            r *= 2
        while l < r:
            m = l + (r - l) // 2
            if works(m):
                r = m
            else:
                l = m + 1
        return l