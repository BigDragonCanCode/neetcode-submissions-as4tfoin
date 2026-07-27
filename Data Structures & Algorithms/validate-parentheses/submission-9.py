class Solution:
    def isValid(self, s: str) -> bool:
        #have a stack to store the left side
        stk = []

        for c in s:
            if c in ['(', '[', '{']:
                stk.append(c)
            else:
                if len(stk) == 0: #means number of brackets does not match
                    return False
                if c == ')' and stk.pop() != '(':
                    return False
                if c == ']' and stk.pop() != '[':
                    return False
                if c == '}' and stk.pop() != '{':
                    return False
        
        return len(stk) == 0 #means number of brackets does not match