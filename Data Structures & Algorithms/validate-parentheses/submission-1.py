class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0: return False 
        stack = []
        
        for c in s:
            if c == '(' or c == '{' or c == '[':
                stack.append(c)
            elif len(stack) == 0:
                return False
            else: 
                if (c == ')' and stack[-1] == '(') or (c == '}' and stack[-1] == '{') or (c == ']' and stack[-1] == '[') :
                    stack.pop()
                else:
                    return False

        return len(stack) == 0