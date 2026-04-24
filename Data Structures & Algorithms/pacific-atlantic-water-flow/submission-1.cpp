class Solution {
public:
    void helper(vector<vector<int>>& graph, vector<vector<int>>& heights, int i, int j, int& rows, int& cols) {
        vector<pair<int, int>> neighbors = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
        graph[i][j] = 1; //mark as a valid flow point (cell)
        for (pair<int, int>& n: neighbors) {
            if (n.first >= rows || n.second >= cols || n.first < 0 || n.second < 0)
                continue;
            if (graph[n.first][n.second] == 1) //already marked
                continue;
            if (heights[n.first][n.second] >= heights[i][j])
                helper(graph, heights, n.first, n.second, rows, cols);    
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        //initialize the graph with 0s
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));
        //those positions can all flow into pacific / atlantic so
        //we need a for loop to gather all possibilities
        //top / bottom
        for (int i=0; i<cols; i++) {
            helper(pacific, heights, 0, i, rows, cols);
            helper(atlantic, heights, rows-1, i, rows, cols);
        }
        //left / right
        for (int i=0; i<rows; i++) {
            helper(pacific, heights, i, 0, rows, cols);
            helper(atlantic, heights, i, cols-1, rows, cols);
        }

        //find which cells can flow into both ocean
        vector<vector<int>> results;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    results.push_back({i,j});
            }
        }
        return results;
    }
};
