class Solution {
public:
    int helper(string& text1, string& text2, vector<vector<int>>& mem, int ind1, int ind2) {
        if (ind1 >= text1.size() || ind2 >= text2.size()) return 0;

        if (mem[ind1][ind2] != -1) return mem[ind1][ind2];

        int temp = 0;
        if (text1[ind1] == text2[ind2])
            temp = helper(text1, text2, mem, ind1+1, ind2+1)+1;
        mem[ind1][ind2] = max({temp,
                                helper(text1, text2, mem, ind1+1, ind2),
                                helper(text1, text2, mem, ind1, ind2+1)});
        return mem[ind1][ind2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        //the longest subsequence when text1 is at i and text2 is at j
        vector<vector<int>> mem(text1.size(), vector<int>(text2.size(), -1));

        return helper(text1, text2, mem, 0, 0);
    }
};
