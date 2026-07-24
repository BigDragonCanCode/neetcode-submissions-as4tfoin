class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res (temperatures.size(), 0);

        //store the ones that are waiting for to be assigned a number
        //value, index pair
        stack<pair<int, int>> stk;

        for (int i=0; i<temperatures.size(); i++) {
            int t = temperatures[i];

            //monotonic stack
            //keep assigning value until invalid
            while (!stk.empty() && t > stk.top().first) {
                pair<int, int> p = stk.top();
                stk.pop();

                res[p.second] = i-p.second;
            }
            stk.push({t, i});
        }
        return res;
    }
};
