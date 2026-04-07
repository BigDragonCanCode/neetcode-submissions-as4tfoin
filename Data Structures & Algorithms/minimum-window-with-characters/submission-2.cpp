class Solution {
public:
    bool all_included(unordered_map<char,int> m, string& t) {
        for (const char& c: t) {
            if (m.find(c) == m.end())
                return false;
            m[c]--;
            if (m[c] == 0) m.erase(c);
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";
        unordered_map<char, int> m; //store char and frequency in window

        int left = 0;
        int right = 0;
        string min_window = s;
        bool found = false;

        //try to find the substring that include all frequencies
        while (right < s.length()) {
            char curr_char = s[right];
            //update frequency
            if (m.find(curr_char) == m.end()) {
                m.emplace(curr_char, 1);

            } else {
                //char is in the window
                m[curr_char]++;     
            }
            //if all included try to reduce the size
            while (all_included(m, t)) {
                found = true;
                string curr_window = s.substr(left, right-left+1);
                min_window = min_window.length() < curr_window.length()? min_window: curr_window;
                m[s[left]]--;
                if (m[s[left]] == 0) m.erase(s[left]);
                left++;
            }
            right++;
        }
        return found? min_window:"";
    }
};
