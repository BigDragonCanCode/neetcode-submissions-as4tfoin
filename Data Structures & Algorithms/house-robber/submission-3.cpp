class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        vector<int> mem(nums.size());

        //mem[i] meaning: the max you can get by robbing house 0-i
        mem[0] = nums[0];
        mem[1] = max(nums[0], nums[1]);

        for (int i=2;i<nums.size();i++) {
            //we can choose not rob house i: take the result mem[i-1]
            //we can choose rob house i: take house i's money + the maximum money you can rob from the prev houses
            mem[i] = max(mem[i-1], mem[i-2] + nums[i]);
        }
        return mem[nums.size()-1];
    }
};
