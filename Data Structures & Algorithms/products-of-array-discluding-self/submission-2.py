class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        #it's going to be everything at the left * everything at the right

        #[1,2,4,6]
        prefix = [1] #[  1,  1, 2,  8]
        postfix = [1] #[48, 24, 6,  1]

        for i in range(1, len(nums)+1):
            prefix.append(prefix[i-1]*nums[i-1])

        for i in range(len(nums)-2, -1, -1):
            postfix.insert(0, postfix[0]*nums[i+1])

        output = []
        for i in range(len(nums)):
            output.append(prefix[i]*postfix[i])
        
        return output