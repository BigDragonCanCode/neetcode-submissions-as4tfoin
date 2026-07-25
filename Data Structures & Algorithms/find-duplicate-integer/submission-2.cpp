class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //nums.size() == n+1
        //range is [1, nums.size()-1]
        
        //treat every value to be a pointer to the position
        //there must be a cycle because the duplicate values will point to the same position

        int slow = 0;
        int fast = 0;

        //this while loop only find the meeting point
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        //we want to find the beginning of the cycle, so it's definitely the duplicate
        //not beginning of the cycle does not mean duplicate

        //the distance of intersection point to the beginning of the cycle
        //equals
        //the distance of the head of the array to the beginning of the cycle

        //no more fast & slow pointer, just 2 slow pointers
        int slow2 = 0;
        while (true) {
            slow2 = nums[slow2];
            slow = nums[slow];
            if (slow2 == slow) {
                break;
            }
        }
        return slow2;
    }
};
