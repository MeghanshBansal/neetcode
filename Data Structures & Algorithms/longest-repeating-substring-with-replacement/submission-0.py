class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counting = [0] * 26
        max_frequency = 0
        max_length = 0
        start = 0 
        end = 0

        while end < len(s):
            counting[ord(s[end]) - ord('A')]+=1
            max_frequency = max(max_frequency, counting[ord(s[end]) - ord('A')])

            while end - start + 1 - max_frequency > k:
                counting[ord(s[start]) - ord('A')] -=1
                start+=1

            max_length = max(max_length, end-start+1)
            end += 1
        
        return max_length
