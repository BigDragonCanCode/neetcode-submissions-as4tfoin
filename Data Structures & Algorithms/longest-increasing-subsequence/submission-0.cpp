class Solution {
public:
    //this feels like a bottom-up, because increasingly building up the solution
    //feels more intuitive than breaking down into smaller problem?
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;

        //best length include position i
        //we don't do best length up to i because we need to know where did the previous subsequence end with
        vector<int> dp(nums.size(),1);

        //sub sequence so either store or skip
        //should we store it? if it only strictly depends on dp[i-1] then we can use var
        //if it depends on multiple vars then we need to store dp
        //we need to depends on multiple here because, dp[i-1] doesn't really give the
        //maximum subsequence.
        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
