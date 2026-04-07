using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre = 1;
        int post = 1;

        vector<int> pres({1});
        vector<int> posts({1});
        vector<int> results;

        for (int i=0; i<nums.size()-1; i++) {
            pre *= nums[i];
            post *= nums[nums.size()-i-1];
            pres.push_back(pre);
            posts.insert(posts.begin(), post);
        }
        for (int i=0; i<nums.size(); i++) {
            results.push_back(pres[i]*posts[i]);
        }
        return results;
    }
};
// nums    = [1,  2,  4,   6]
// postfix = [48, 24, 6,  1] ( product of everything to the RIGHT of index i) NONINCLUSIVE of i
// prefix  = [1,  1,   2,  8] ( product of everything to the LEFT of index i)