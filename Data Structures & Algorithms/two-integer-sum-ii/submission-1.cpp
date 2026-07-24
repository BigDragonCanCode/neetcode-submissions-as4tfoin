class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> nums;
        for (int i=0; i<numbers.size(); i++) { //O(n)
            nums.emplace(numbers[i], i);
        }

        for (int i=0; i<numbers.size(); i++) {
            int t = target-numbers[i];
            if (nums.find(t) != nums.end()) {
                return {i+1, nums[t]+1}; 
            }
        }
        return {-1, -1};
    }
};
