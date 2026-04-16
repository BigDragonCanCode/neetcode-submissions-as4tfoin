class Solution {
public:
    bool helper(vector<vector<char>>& board, string remaining, int i, int j) {
        if (remaining == "") //found
            return true;
        if (i >= board.size() || j>=board[0].size() || i<0 || j<0) //out-of-bound
            return false;
        if (board[i][j] != remaining[0]) //not the word we want
            return false;

        string new_remaining = remaining.substr(1);
        char temp = board[i][j];

        board[i][j] = '#'; //visited mark

        bool found = helper(board, new_remaining, i+1, j) || 
        helper(board, new_remaining, i-1, j) ||
        helper(board, new_remaining, i, j+1) ||
        helper(board, new_remaining, i, j-1);

        board[i][j] = temp; //restore original value

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        //traverse through all the board
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (helper(board, word, i, j))
                    return true;
            }
        }
        return false;
    }
};
