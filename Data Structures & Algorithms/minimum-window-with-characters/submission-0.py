class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "": 
            return ""
        
        window, countT = dict(), dict()
        
        for c in t:
            countT[c] = countT.get(c, 0) + 1
        
        have, want = 0, len(t)
        res = []
        resultLen = float('inf')
        
        start = 0
        end = 0
        while end < len(s):
            window[s[end]] = window.get(s[end], 0) + 1
            if s[end] in countT and window[s[end]] <= countT[s[end]]:
                have +=1
                
            #moving the start pointer
            while have == want: 
                if end - start + 1 < resultLen:
                    res = [start, end + 1]
                    resultLen = end - start + 1
                window[s[start]] = window.get(s[start], 0) - 1
                if s[start] in countT and window[s[start]] < countT[s[start]]:
                    have -= 1
                start+=1
            end += 1
        
        if resultLen != float('inf'):
            return s[res[0]: res[1]]
        else : 
            return ""