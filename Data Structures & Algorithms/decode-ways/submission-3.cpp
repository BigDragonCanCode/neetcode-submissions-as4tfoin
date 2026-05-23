
class Solution {
public:
    int helper(string& s, unordered_map<int,int>& mem, int start) {
        //when we reach the end we know we found a right path
        if (start >= s.length()) return 1;
        if (s[start] == '0') return 0;

        if (mem.count(start)) return mem[start];

        int ways = 0;

        //1 digit
        ways += helper(s, mem, start+1);

        if (start+1 < s.size()) {
            int temp = stoi(s.substr(start,2));
            if (temp <= 26) {
                ways += helper(s, mem, start+2);
            }
        }

        mem[start] = ways;
        return ways;

    }

    int numDecodings(string s) {
        unordered_map<int,int> mem;
        mem[s.size()] = 1; // base case
        return helper(s, mem, 0);
    }
};
