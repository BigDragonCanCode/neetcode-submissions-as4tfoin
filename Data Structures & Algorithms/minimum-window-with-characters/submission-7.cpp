class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        unordered_map<char, int> need;

        //set need for fast lookup O(m)
        for (char& c: t) {
            need[c]++;
        }

        int left = 0;
        int right = 0;
        int have = 0;
        int start = 0;
        int end = INT_MAX;

        while (right < s.size()) {
            freq[s[right]]++;

            //if the needed char appear and the # of occurrence is satisfied
            if (need.count(s[right]) && need[s[right]] == freq[s[right]]) {
                have+=need[s[right]];
            }

            //try reduce the window until it's not valid anymore and continue
            while (have == t.size()) {
                freq[s[left]]--;
                if (need.count(s[left]) && freq[s[left]]<need[s[left]]) {
                    //only update the substr when it's better
                    if (right-left < end-start) {
                        start = left;
                        end = right;
                    }
                    have-=need[s[left]];
                }
                left++;
            }
            right++;
        }
        return end == INT_MAX ? "" : s.substr(start,end-start+1);

    }
};
