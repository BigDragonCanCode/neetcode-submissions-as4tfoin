class Solution {
public:
    //sweep line
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //build map
        //+1 for start and -1 for end
        //already sorted
        map<int, int> mp;
        for(const vector<int>& i: intervals) {
            mp[i[0]]++;
            mp[i[1]]--;
        }

        vector<vector<int>> res;
        vector<int> interval;
        int num = 0;
        
        for (const auto& [i, count]: mp) {
            if (interval.empty()) {
                interval.push_back(i); //get the start
            }
            num += count;
            //when there's no overlap, num should be 0
            if (num == 0) {
                interval.push_back(i); //get the end
                res.push_back(interval);
                interval.clear();
            }
        }
        return res;

    }
};
