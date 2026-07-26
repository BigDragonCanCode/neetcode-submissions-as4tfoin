class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        count = Counter(nums)

        for value, occurrence in count.items():
            if (occurrence > 1):
                return True

        return False