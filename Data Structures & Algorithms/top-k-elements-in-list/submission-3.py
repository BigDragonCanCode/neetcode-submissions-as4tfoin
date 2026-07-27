class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)

        #0....n
        #the max frequency is bounded by length of nums list
        bucket = [[] for _ in range(len(nums)+1)]

        for key,val in count.items():
            # bucket[val] = key
            bucket[val].append(key) #because it's possibe for key to have same frequency

        #we loop from the maximum frequency to the lowest
        #when find k frequencies we stop
        res = []
        for i in range(len(bucket)-1, 0, -1):
            for n in bucket[i]:
                if len(res) == k:
                    break
                res.append(n)
        return res