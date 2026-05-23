class Solution {
public:

    //top down
    int helper(vector<int>& nums, vector<int>& mem_max, vector<int>& mem_min, int curr) {
        if (curr == nums.size()) return 1;

        if (mem_max[curr]) return mem_max[curr];

        //include + skip
        //this is not correct because it does not preserve contiguity
        //its like finding the maximum product instead of maximum subarray
        //int r = max(helper(nums, mem, curr+1) * nums[curr], helper(nums,mem,curr+1));

        //this is still not correct because double negative=positive, so only taking the maximum
        //may miss the real maximum product
        //mem[curr] = max(nums[curr], helper(nums, mem, curr+1) * nums[curr]);

        mem_max[curr] = max(nums[curr], helper(nums, mem_max, mem_min, curr+1) * nums[curr]);
        mem_min[curr] = min(nums[curr], helper(nums, mem_max, mem_min, curr+1) * nums[curr]);

        return mem_max[curr]; //it feels weird what should i return? maybe bottom-up is better
    }

    int maxProduct(vector<int>& nums) {
        // vector<int> mem_max(nums.size());
        // vector<int> mem_min(nums.size());
        // return helper(nums, mem_max, mem_min, 0);

        //bottom-up
        int maxx = nums[0];
        int minn = nums[0];
        int ans = nums[0];
        for (int i=1; i<nums.size(); i++) {
            int currMax = maxx;
            int currMin = minn;
            //option1: multiply with max
            //option2: multiply with min, see if we can do double-negative
            //option3: start a new subarray
            maxx = max({currMax * nums[i], currMin * nums[i], nums[i]});
            minn = min({currMax * nums[i], currMin * nums[i], nums[i]});

            ans = max(maxx, ans);
        }
        return ans;
    }
};
