class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [0] * len(temperatures)
        stack = [(temperatures[-1], len(temperatures) - 1 )]
        for i in range(len(temperatures) - 2, -1, -1):
            while len(stack) != 0 and temperatures[i] >= stack[-1][0]:
                stack.pop()
                
            if len(stack) == 0:
                ans[i] = 0
            else:
                ans[i] = stack[-1][1] - i
            stack.append((temperatures[i], i))
        
        return ans