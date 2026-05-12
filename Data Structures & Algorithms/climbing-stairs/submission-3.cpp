class Solution {
public:
    //O(2^n) too inefficient
    // int helper(int& n, int sum) {
    //     if (sum == n) {
    //         return 1;
    //     }
    //     if (sum < n) {
    //         return helper(n,sum+1) + helper(n,sum+2);
    //     }
    //     return 0;
    // }

    int helper(int&n, int curr, vector<int>& mem) {
        if (curr == n) {
            return 1;
        }
        if (curr > n) {
            return 0;
        }
        //already computed
        if (mem[curr] != 0) {
            return mem[curr];
        }
        mem[curr] = helper(n, curr+1, mem) + helper(n, curr+2, mem);
        return mem[curr];
    }

    //top-down: start from the final problem and recusively ask for smaller ones
    int climbStairs(int n) {
        vector<int> mem(n+1); //from 0-n
        mem[n] = 1;
        
        return helper(n,0,mem);
    }
};
