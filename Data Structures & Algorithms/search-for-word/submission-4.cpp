class Solution {
public:
    /*we used to use
    * bool helper(vector<vector<char>>& board, string remaining, int i, int j)
    * and check for if remaining is empty
    * but it requires a copy of remaining and it's a waste of space
    */
    bool helper(vector<vector<char>>& board, string& word, int idx, int i, int j) {
        if (idx == word.size()) //found
            return true;
        if (i >= board.size() || j>=board[0].size() || i<0 || j<0) //out-of-bound
            return false;
        if (board[i][j] != word[idx]) //not the word we want
            return false;

        char temp = board[i][j];

        board[i][j] = '#'; //visited mark

        bool found = helper(board, word, idx+1, i+1, j) || 
        helper(board, word, idx+1, i-1, j) ||
        helper(board, word, idx+1, i, j+1) ||
        helper(board, word, idx+1, i, j-1);

        board[i][j] = temp; //restore original value

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        //traverse through all the board
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (helper(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
