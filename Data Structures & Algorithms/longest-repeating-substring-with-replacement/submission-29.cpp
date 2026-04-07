class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;

        unordered_map<char, int> m; //char, freq
        int max_freq = 0;

        int result = 0;
        while (right < s.length()) {
            char curr_char = s[right];
            int curr_size = right - left + 1;
            
            //we are trying to update frequency
            //if the char is not in the window
            if (m.find(curr_char) == m.end()) {
                m.emplace(curr_char, 1);

            } else {
                //char is in the window
                m[curr_char]++;     
            }

            //update max frequency and check whether valid or not
            for (const auto& a: m) {
                if (a.second > max_freq)
                    max_freq = a.second;
            }

            //invalid we need to reduce frequency and window
            if (curr_size - max_freq > k) {
                m[s[left]]--;
                if (m[s[left]] == 0) m.erase(s[left]);
                left++;
            }


            result = max(result, right - left + 1);
            // cout<<left<<" "<<right<<" "<<max_freq<<" "<<result<<endl;
            right++;
        }
        return result;
    }
};
