class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def generateAll(n, open, close, curr, ans):
            if close == n:
                ans.append(curr)
                return 
            if open < n: 
                generateAll(n, open+1, close, curr + "(", ans)
            if close < open: 
                generateAll(n, open, close + 1, curr + ")", ans)
            return 

        ans = []
        generateAll(n, 0, 0, "", ans)
        return ans