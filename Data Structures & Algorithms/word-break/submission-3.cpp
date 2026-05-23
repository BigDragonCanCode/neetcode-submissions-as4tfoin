class Solution {
public:

    bool helper(string& s, vector<string>& wordDict, vector<int>& mem, int curr) {
        if (curr == s.size()) return true;
        if (curr > s.size()) return false;

        if (mem[curr] != -1) return mem[curr];

        bool found = false;
        for (string& w: wordDict) {
            if (curr+w.size() <= s.size() && s.substr(curr, w.size()) == w)
                found = found || helper(s, wordDict, mem, curr+w.size());
        }

        mem[curr] = found;
        return found;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //can substr start at i be segmented?
        vector<int> mem(s.size(), -1);

        helper(s, wordDict, mem, 0);

        return mem[0];
    }
};
