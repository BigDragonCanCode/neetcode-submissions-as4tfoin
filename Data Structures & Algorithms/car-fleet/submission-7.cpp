class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int res = 0;
        
        //first we sort by position descendingly
        vector<pair<int, int>> pairs;
        for (int i = 0; i < position.size(); i++) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());

        stack<double> stk;
        //monotonic stack
        for (auto& p: pairs) {
            //integer does not work because we care about the exact arrival time
            //if the first car reaches the destination a little before the next car
            //they are not considered as met at the destination
            // int step = ceil((double)(target - p.first) / p.second);
            double step = (double)(target - p.first) / p.second;

            //if the current car takes less step than the car ahead of it,
            //they will become a fleet before finish the ride
            if (!stk.empty() && step <= stk.top()) { 
                //pass, it's a fleet
            } else {
                stk.push(step);
            }
        }

        return stk.size();
    }
};
