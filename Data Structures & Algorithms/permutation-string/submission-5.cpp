class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        //we have 26 chars only so it can be generalized to O(1)...
        vector<int> map1(26,0);
        vector<int> map2(26,0);

        //build the initial frequency map
        for (int i=0; i<s1.size(); i++) {
            map1[s1[i]-'a']++;
            map2[s2[i]-'a']++;
        }

        int matches = 0;
        for (int i=0; i<26; i++) {
            if (map1[i] == map2[i]) {
                matches++;
            }
        }
        if (matches == 26) {
            return true;
        }

        for (int i=s1.size(); i<s2.size(); i++) {
            map2[s2[i]-'a']++;
            map2[s2[i-s1.size()]-'a']--;

            int matches = 0;
            for (int j=0; j<26; j++) {
                if (map1[j] == map2[j]) {
                    matches++;
                }
            }
            if (matches == 26) {
                return true;
            }
        }

        return false;
    }
};
