class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        dictionary = [0 for _ in range(256)]
        for i in s:
            dictionary[ord(i) - ord('a')] += 1
        
        for i in t:
            dictionary[ord(i) - ord('a')]-=1

        for i in dictionary:
            if i < 0: 
                return False
        return True