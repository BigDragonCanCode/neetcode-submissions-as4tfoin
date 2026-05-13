class Solution {
public:
    //start from the final answer
    //and recursively narrow down to smaller problems
    int top_down(vector<int>& nums, vector<int>& mem, int curr) {
        if (curr < 0) return 0;
        if (curr == 0) return nums[0];

        if (mem[curr] != 0) return mem[curr];

        int skipCurr = top_down(nums, mem, curr-1);
        int robCurr = top_down(nums, mem, curr-2) + nums[curr];

        mem[curr] = max(skipCurr, robCurr);
        return mem[curr];
    }

    int rob(vector<int>& nums) {
        vector<int> mem(nums.size());

        return top_down(nums, mem, nums.size()-1);
    }
};
