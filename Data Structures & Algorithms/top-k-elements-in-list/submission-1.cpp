class Solution {
public:
    //try bucket sort??
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //build a frequency map
        unordered_map<int, int> mp; //num, frequency
        for (int& n: nums) {
            mp[n]++;
        }

        //put the nums into their frequency buckets
        vector<vector<int>> buckets(nums.size()+1);
        for (auto i=mp.begin(); i!=mp.end(); i++) {
            buckets[i->second].push_back(i->first);
        }

        //get the top k frequencies from the bucket
        vector<int> res;
        for (int i=buckets.size()-1; i>=0; i--) {
            if (k==0) break;
            for (int j=0; j<buckets[i].size(); j++) {
                if (k==0) break;
                res.push_back(buckets[i][j]);
                k--;
            }
        }
        return res;
    }
};
