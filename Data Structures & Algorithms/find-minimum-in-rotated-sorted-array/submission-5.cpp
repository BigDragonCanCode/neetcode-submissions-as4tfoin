class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        if (nums[0] <= nums[nums.size()-1]) return nums[0]; //sorted
        
        //when left == right the answer is found
        while (left < right) {
            int mid = (left+right)/2;
            
            if (nums[mid] >= nums[right]) //min is at the right side, not including mid
                left = mid+1;
            else //min is at the left side may include mid
                right = mid;

        }

        return nums[left];
    }
};
