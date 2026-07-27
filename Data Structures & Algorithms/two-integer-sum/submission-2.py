class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = dict()

        for i in range(len(nums)):
            other_num = target - nums[i]

            if m.get(other_num) is not None:
                # nums[i] is at the first because it's def smaller than i
                return [m[other_num], i]

            #update at the last step, consider 10=5+5 case
            m[nums[i]] = i

        return []




        