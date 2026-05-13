class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        bool finished = false;
        //outer control layers, goes from outer square to inner square
        //only perform for the upper half, it's very accurate
        for (int i=0; i<matrix.size()/2; i++) {
            //swap the 4 vars, do that for all numbers in the current layer
            for (int j=0; j<matrix[0].size()-i*2-1; j++) {
                pair<int, int> upper_left = {i,i+j};
                pair<int, int> upper_right = {i+j,matrix[0].size()-1-i};
                pair<int, int> lower_left = {matrix.size()-1-i-j,i};
                pair<int, int> lower_right = {matrix.size()-1-i,matrix[0].size()-1-i-j};
                cout<<upper_left.first<<" "<<upper_left.second<<endl;
                cout<<upper_right.first<<" "<<upper_right.second<<endl;
                cout<<lower_left.first<<" "<<lower_left.second<<endl;
                cout<<lower_right.first<<" "<<lower_right.second<<endl;
                cout<<"----------"<<endl;
                
                //perform swap
                // pair<int, int> temp = upper_left; <-this only store the coordinates not the original value
                int temp = matrix[upper_left.first][upper_left.second];
                matrix[upper_left.first][upper_left.second] = matrix[lower_left.first][lower_left.second];
                matrix[lower_left.first][lower_left.second] = matrix[lower_right.first][lower_right.second];
                matrix[lower_right.first][lower_right.second] = matrix[upper_right.first][upper_right.second];
                matrix[upper_right.first][upper_right.second] = temp;

            }
            if (finished) {
                break;
            }
        }
    }
};
