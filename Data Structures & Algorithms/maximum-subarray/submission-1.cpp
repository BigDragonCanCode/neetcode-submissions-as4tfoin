class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];

        for (int i=1; i<nums.size(); i++) {
            //if the previous array is not helpful, just drop it
            if (sum < 0) {
                sum = nums[i];
                ans = max(ans, sum);
                continue;
            }
            sum += nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
