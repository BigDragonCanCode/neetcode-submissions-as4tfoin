class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //store frequencies in hash_map
        unordered_map<int, int> freqs;
        for (int i=0; i<nums.size(); i++) {
            freqs[nums[i]]++;
        }

        set<vector<int>> res;
        //fix 2 numbers and find the 3rd one
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                int n1 = nums[i];
                int n2 = nums[j];
                int t = 0 - n1 - n2; //the num we want to find

                freqs[n1]--;
                freqs[n2]--;

                if (freqs.find(t) != freqs.end() && freqs[t] != 0) {
                    vector<int> r = {n1,n2,t};
                    sort(r.begin(), r.end());
                    res.insert(r);
                }

                freqs[n1]++;
                freqs[n2]++;
            }
        }

        vector<vector<int>> results;
        for (const auto& r: res) {
            results.push_back(r);
        }
        return results;
    }
};
