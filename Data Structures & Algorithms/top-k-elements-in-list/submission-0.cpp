class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; //number, frequency

        //generate the frequency map
        for (int& n: nums) {
            if (m.find(n) == m.end()) {
                m.emplace(n, 1);
            } else {
                m[n]++;
            }
        }

        //sort
        vector<pair<int ,int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int>b){
            return a.second > b.second;
        });

        vector<int> results;
        for (int i=0; i<k; i++) {
            results.push_back(vec[i].first);
        }

        return results;
    }
};
