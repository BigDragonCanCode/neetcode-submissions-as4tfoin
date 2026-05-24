class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int ind = -1;
        for (int i=0; i<intervals.size(); i++) {
            //interval ends before new starts - ignore
            if (newInterval[0] > intervals[i][1]) {
                continue;
            }
            //interval start after new ends - insert before
            else if (newInterval[1] < intervals[i][0]) {
                intervals.insert(intervals.begin()+i, newInterval);
                return intervals;
            }
            //there is overlap
            else {
                intervals[i][0] = min(intervals[i][0], newInterval[0]);
                intervals[i][1] = max(intervals[i][1], newInterval[1]);
                
                int j=i+1;
                while (j<intervals.size() && intervals[j][0] <= intervals[i][1]) {
                    intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                    intervals.erase(intervals.begin()+j);
                }
                return intervals;
            }
        }

        //case: we never inserted/merged
        intervals.push_back(newInterval);
        return intervals;
    }
};
