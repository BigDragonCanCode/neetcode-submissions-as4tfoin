class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if goal can reach the end, and i can reach goal, then i can reach the end too
        int goal = nums.size()-1;

        for (int i=nums.size()-2; i>=0; i--) {
            //we can jump to goal, and then we can update our goal to be smaller
            //I had a question that: what if the only valid path cannot reach the new goal
            //but can reach the end, will updating the goal break the algorithm?
            //A: it will not. because we are not checking if we can reach the exact new goal,
            //but also cover the case greater than that
            //so if this path can reach the end, then it must first be able to reach the new goal
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }
};
