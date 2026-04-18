class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> copy = grid;
        int result = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    helper(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
private:
    //find all cells of the island and mark them as 0
    void helper(vector<vector<char>>& grid, int i, int j) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return; //invalid range
        if (grid[i][j] == '#' || grid[i][j] == '0') return; //not visiting the path we visited
        grid[i][j] = '#';
        helper(grid, i-1, j);
        helper(grid, i+1, j);
        helper(grid, i, j-1);
        helper(grid, i, j+1);
        grid[i][j] = '0';
    }
};
