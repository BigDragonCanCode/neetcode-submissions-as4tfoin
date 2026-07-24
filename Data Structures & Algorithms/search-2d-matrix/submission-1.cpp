class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //first figure out which row
        int l = 0;
        int r = matrix.size() - 1;

        int colSize = matrix[0].size();

        int row = -1;
        while (l <= r) {
            int mid = l + (r-l) / 2;

            // in the previous rows
            if (target < matrix[mid][0]) {
                r = mid - 1;
            } else if (target > matrix[mid][colSize-1]) {
                l = mid + 1;
            } else {
                row = mid;
                break;
            }
        }

        if (row == -1) {
            return false;
        }

        if (matrix[row][0] == target) {
            return true;
        }
        //next figure out the exact position in the row

        l = 0;
        r = colSize-1;

        while (l<=r) {
            int mid = l + (r-l) / 2;
            if (target < matrix[row][mid]) {
                r = mid - 1;
            } else if (target > matrix[row][mid]) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
