class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0 || s.length() == 1) return s.length();

        int left = 0;
        int right = 1;
        int max_sub = -1;
        unordered_map<char, int> seen; //char, index
        seen.emplace(s[0], 0);

        while (right < s.length()) {
            //if never seen, add entry
            if (seen.find(s[right]) == seen.end()) {
                seen.emplace(s[right], right);
            }
            //if seen but outside of window ignore
            else if(seen[s[right]] < left) {
                seen[s[right]] = right;
            }
            //if within window, update start position to the right of duplicate seen index
            //and update seen index with curr index (right)
            else {
                max_sub = max(max_sub, right - left);
                cout<<"before "<<left<<" "<<right<<endl;
                left = seen[s[right]]+1;
                seen[s[right]] = right;
                cout<<"after "<<left<<" "<<right<<endl;
            }
            right++;
        }
        max_sub = max(max_sub, right - left);
        return max_sub;
    }
};
