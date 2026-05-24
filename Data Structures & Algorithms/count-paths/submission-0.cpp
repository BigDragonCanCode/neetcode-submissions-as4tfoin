class Solution {
public:
    int helper(int& m, int& n, vector<vector<int>>& mem, int x, int y) {
        if (x == m-1 && y == n-1) return 1;
        if (x >= m || y >= n) return 0;

        if (mem[x][y]) return mem[x][y];

        mem[x][y] = helper(m, n, mem, x+1, y) + helper(m, n, mem, x, y+1);
        return mem[x][y];
    }

    int uniquePaths(int m, int n) {
        //the number of unique path to reach the goal at position x,y
        vector<vector<int>> mem(m,vector<int>(n));

        return helper(m, n, mem, 0, 0);
    }
};
