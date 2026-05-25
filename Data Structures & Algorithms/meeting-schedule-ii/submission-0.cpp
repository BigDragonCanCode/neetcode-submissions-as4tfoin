/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        for (auto& i: intervals) {
            mp[i.start]++;
            mp[i.end]--;
        }
        int count = 0;
        int ans = 0;

        for(auto& [key,val]: mp) {
            count += val;
            ans = max(ans, count);
        }
        return ans;
    }
};
