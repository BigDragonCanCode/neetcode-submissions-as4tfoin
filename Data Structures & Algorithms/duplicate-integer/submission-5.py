class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        #dictionary

        count = dict()

        for n in nums:
            count[n] = count.get(n,0) + 1
            if (count[n] > 1):
                return True
        return False

        
        
        