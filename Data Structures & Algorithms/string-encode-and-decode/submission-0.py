class Solution:

    def encode(self, strs: List[str]) -> str:
        if not strs:
            return ""   
        
        encoded = ""
        
        for string in strs:

            length = str(len(string))
            

            encoded += length + ":" + string
        
        return encoded

    def decode(self, s: str) -> List[str]:
        if not s:
            return []
        
        decoded = []
        
        i = 0
        
        while i < len(s):

            length = ""
            

            while s[i] != ":":
                length += s[i]
                i += 1
            

            i += 1
            

            string = s[i:i+int(length)]
            

            decoded.append(string)
            

            i += int(length)
        
        return decoded
