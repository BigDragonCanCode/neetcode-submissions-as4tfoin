class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            //num xor itself should cancel out
            res = res ^ i ^ nums[i];
        }
        //for loop loop through 0...n-1, so we still need to check n
        res = res ^ nums.size();
        return res;
    }
};
