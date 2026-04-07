class Solution {
public:
    int area(int dist, int l_h, int r_h) {
        return dist * min(l_h, r_h);
    }

    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int max_area = area(right-left, heights[left], heights[right]);

        while (left < right) {
            //try updating the pointers
            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
            int curr_area = area(right-left, heights[left], heights[right]);
            if (curr_area > max_area) {
                max_area = curr_area;
            }
        }
        return max_area;
    }
};
