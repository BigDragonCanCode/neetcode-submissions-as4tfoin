class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int len = 1;
        int res = 1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] - nums[i-1] == 1) {
                len++;
                continue;
            } else if (nums[i] - nums[i-1] == 0) {
                continue;
            }
            res = res > len ? res:len;
            len = 1;
        }
        res = res > len ? res:len;
        return res;
    }
};
