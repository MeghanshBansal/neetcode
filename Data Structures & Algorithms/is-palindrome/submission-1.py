class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        i, j = 0, len(s) -1 

        while i <= j:
            while i < j and  re.match("[A-Za-z0-9]", s[i]) is None: 
                i+=1

            while i < j and re.match("[A-Za-z0-9]", s[j]) is None:
                j-=1

            if s[i] != s[j]: return False
            i+=1
            j-=1 
        return True 
