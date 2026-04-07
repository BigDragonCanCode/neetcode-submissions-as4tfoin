using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; //number, index

        for (int i=0; i<nums.size(); i++) {
            int other_num = target - nums[i];
            
            if (m.find(other_num) != m.end()) {
                return { m[other_num], i};
            }
            m.emplace(nums[i], i);
        }
        
        return {};
    }
};
