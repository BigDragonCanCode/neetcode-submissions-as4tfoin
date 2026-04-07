
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> dict; //word, index
        vector<vector<string>> results;
        int size = 0;

        for (string str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            
            if (dict.find(s) != dict.end()) {
                int idx = dict[s];
                results[idx].push_back(str);
            } else {
                dict.emplace(s, size);
                results.push_back({str});
                size++;
            }
        }

        return results;
    }
};
