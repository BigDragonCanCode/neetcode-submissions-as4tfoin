class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort by start time
        sort(intervals.begin(), intervals.end());

        //always removing the overlap with larger end time, because it will block the future
        //intervals more
        int ans = 0;
        int prevEnd = intervals[0][1];
        for (int i=1; i<intervals.size(); i++) {
            //overlap detected
            if (intervals[i][0] < prevEnd) {
                prevEnd = min(prevEnd, intervals[i][1]);
                ans++;
            } else {
                //no overlap just update prevEnd
                prevEnd = intervals[i][1];
            }
        }
        return ans;
    }
};
