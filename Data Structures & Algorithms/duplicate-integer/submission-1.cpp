class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> arr;
        for (int num: nums) {
            if (arr.find(num) != arr.end())
                return true;
            arr.insert(num);
        }
        return false;
    }
};