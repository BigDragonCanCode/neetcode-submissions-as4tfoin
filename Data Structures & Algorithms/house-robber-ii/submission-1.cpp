class Solution {
public:
    int top_down(vector<int>& nums, vector<int>& memo, int curr, int& end) {
        if (curr < end) return 0;
        if (curr == end) return nums[curr];

        if (memo[curr] != 0) return memo[curr];

        int rob = top_down(nums, memo, curr-2, end) + nums[curr];
        int noRob = top_down(nums, memo, curr-1, end);
        
        memo[curr] = max(rob, noRob);
        return memo[curr];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> memo(nums.size());
        vector<int> memo2(nums.size());

        int end = 0;
        int robFirst = top_down(nums, memo, nums.size()-2, end); //rob the first house, skip the last one
        end = 1;
        int noRobFirst = top_down(nums, memo2, nums.size()-1, end); //skip the first, rob the last

        return max(robFirst, noRobFirst);
    }
};
