class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if (len(s) != len(t)):
            return False

        count1 = Counter(s)
        count2 = Counter(t)

        for key, val in count1.items():
            if count2[key] != val:
                return False

        return True