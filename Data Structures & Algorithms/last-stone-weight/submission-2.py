from heapq import heappush, heappop, heapify

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if len(stones) == 0: return None
        elif len(stones) == 1: return stones[0]
        stones = list(map(lambda x: x * -1, stones))
        heapify(stones)
        
        
        while len(stones) != 1: 
            x, y = -1 * heappop(stones),-1 *  heappop(stones)
            res = None
            if x == y: 
                res = 0
            elif x > y: 
                res = x - y
            else: 
                res = y - x
                
            heappush(stones, -1 * res)
        
            
        return stones[0] * -1