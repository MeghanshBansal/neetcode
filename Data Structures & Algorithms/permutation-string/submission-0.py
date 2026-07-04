class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2) : 
            return False
            
        windowSize = len(s1)
        charsInS1 = [0] * 26
        for c in s1:
            charsInS1[ord(c) - ord('a')] +=1
        
        charInWindow = [0] * 26
        
        def checkWindowEqualsS1():
            for i in range(26):
                if charsInS1[i] != charInWindow[i]: return False
            return True
        
        
        for i in range(windowSize):
            charInWindow[ord(s2[i]) - ord('a')]+=1
        
        if checkWindowEqualsS1(): return True
        for i in range(windowSize, len(s2)):
            charInWindow[ord(s2[i]) - ord('a')]+=1
            charInWindow[ord(s2[i - windowSize]) - ord('a')]-=1
            if checkWindowEqualsS1(): return True 
        return False