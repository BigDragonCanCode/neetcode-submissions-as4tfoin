class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;

        //the area is capped by the lowest wall
        int lmax = height[l];
        int rmax = height[r];

        int area = 0;

        while (l < r) {
            if (lmax < rmax) {
                l++;
                lmax = max(lmax, height[l]);
                area += lmax - height[l];
                
            } else {
                r--;
                rmax = max(rmax, height[r]);
                area += rmax - height[r];
                
            }
        }
        return area;
    }
};
