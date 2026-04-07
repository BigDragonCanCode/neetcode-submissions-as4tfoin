class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        make_heap(nums.begin(), nums.end(), greater<int>());

        int len = 1;
        int res = 1;

        
        int prev = nums.front();
        pop_heap(nums.begin(), nums.end(), greater<int>());
        nums.pop_back();

        while (nums.size() != 0) {
            int curr = nums.front();
            pop_heap(nums.begin(), nums.end(), greater<int>());
            nums.pop_back();
            if (curr - prev == 1) {
                len++;
            } else if (curr - prev != 0) {
                res = res > len ? res:len;
                len = 1;
            }
            prev = curr;
        }
        res = res > len ? res:len;
        return res;
    }
};
