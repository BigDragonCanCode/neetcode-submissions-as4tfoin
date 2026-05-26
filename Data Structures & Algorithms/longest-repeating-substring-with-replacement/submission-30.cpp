class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;

        // unordered_map<char, int> m; //char, freq
        vector<int> m(26); //this avoids hashing
        int max_freq = 0;

        int result = 0;
        while (right < s.length()) {
            int l_char = s[left] - 'A';
            int r_char = s[right] - 'A';
            int curr_size = right - left + 1;
            
            //we are trying to update frequency
            m[r_char]++;     

            //update max frequency and check whether valid or not
            max_freq = max(max_freq, m[r_char]);

            //invalid we need to reduce frequency and window
            if (curr_size - max_freq > k) {
                m[l_char]--;
                left++;
            }

            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};
