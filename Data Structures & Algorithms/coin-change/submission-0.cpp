class Solution {
public:
    //this is not a greedy problem because:
    //taking the maximum does not guarantee fewest coins
    //[1,3,4] 6: 3+3 is better than 4+1+1

    int helper(vector<int>& coins, vector<int>& mem, int amount) {
        if (amount < 0) return INT_MAX;
        if (amount == 0) return 0;

        if (mem[amount]) return mem[amount];

        int res = INT_MAX;
        //try for every coin
        for (int& c: coins) {
            int temp = helper(coins, mem, amount-c);
            if (temp != INT_MAX) //we need this check, otherwise INT_MAX+1 will overflow to a negative num
                res = min(res, temp+1);
        }
        mem[amount] = res;
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> mem(amount+1); //fewest coin to reach amount
        helper(coins, mem, amount);
        return mem[amount] == INT_MAX ? -1 : mem[amount];
    }
};
