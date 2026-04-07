using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; //number, index

        for (int i=0; i<nums.size(); i++) {
            int other_num = target - nums[i];
            
            cout<<nums[i]<<" "<<i<<endl;
            if (m.find(other_num) != m.end()) {
                cout<<m[i]<<" "<<m[other_num]<<endl;
                return { m[other_num], i};
            }
            m.emplace(nums[i], i);
        }
        
        return {};
    }
};
