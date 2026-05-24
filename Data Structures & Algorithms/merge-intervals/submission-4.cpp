class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = {intervals[0]};
        int i=1;
        while (i<intervals.size()) {
            if (intervals[i][0] >= res[res.size()-1][0] && intervals[i][0] <= res[res.size()-1][1]) {
                cout<<"merge"<<endl;
                int start = min(intervals[i][0], res[res.size()-1][0]);
                int end = max(intervals[i][1], res[res.size()-1][1]);
                res[res.size()-1]={start,end};
                // intervals.erase(intervals.begin()+i); //O(n)
                i++;

            } else {
                cout<<"huh"<<endl;
                res.push_back(intervals[i]);
                i++;
            }
        }
        return res;
    }
};
