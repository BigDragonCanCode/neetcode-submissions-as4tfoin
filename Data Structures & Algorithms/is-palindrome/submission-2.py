class Solution:
    def isPalindrome(self, s: str) -> bool:
        def isValid(s: str) -> bool:
            return ((ord(s) >= 65 and ord(s) <= 90) or
            (ord(s) >= 97 and ord(s) <= 122) or
            s.isdigit())

        #case insensitive
        s = s.lower()

        l=0
        r=len(s)-1

        while l<=r:
            if not isValid(s[l]):
                l+=1
                continue
            if not isValid(s[r]):
                r-=1
                continue
            
            #both are valid, compare
            if s[l] != s[r]:
                return False
            l+=1
            r-=1
        
        return True

