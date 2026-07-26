from collections import Counter

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        freq = Counter(nums)
        
        res = set()

        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                v1 = nums[i]
                v2 = nums[j]

                target = 0 - (v1+v2)

                freq[v1] -= 1
                freq[v2] -= 1

                if freq[target] > 0:
                    #list is not hashable, need to turn it to tuple first
                    #tuple has no .sort() so needs to use sorted() to return a new sorted tuple
                    triplet = tuple(sorted([v1, v2, target]))
                    res.add(triplet)
                
                freq[v1] += 1
                freq[v2] += 1
        
        return [list(triplet) for triplet in res]