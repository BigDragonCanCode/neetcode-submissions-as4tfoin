class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        //make a hash set
        unordered_set<int> s;
        for (int& n: nums) {
            s.insert(n);
        }

        int len = 0;
        int res = 0;

        for (int i=0; i<nums.size(); i++) {
            int curr = nums[i];
            //trying to find the smallest of the sequence
            while (s.find(curr-1) != s.end()) {
                curr--;
            }
            //count
            while (s.find(curr) != s.end()) {
                len++;
                curr++;
            }
            //update
            res = res > len? res:len;
            len = 0;
        }

        return res;
    }
};
