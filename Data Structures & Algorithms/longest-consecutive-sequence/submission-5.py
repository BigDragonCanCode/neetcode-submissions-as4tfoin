class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        m = set()

        #duplicate is not counted so we are free to use set
        for n in nums:
            m.add(n)

        res = 0

        for num in m:
            #means the number is not the smallest we just ignore
            if num-1 in m:
                pass

            #find the start of the sequence, count
            curr_count = 0
            curr_num = num
            while curr_num in m:
                curr_count += 1
                res = max(res, curr_count)
                curr_num += 1


        return res