class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) return 0;

        int max_profit = 0;
        int start = 0;
        for (int i=0; i<prices.size(); i++) {
            if (prices[start] > prices[i]) {
                start = i;
            }
            max_profit = max(max_profit, prices[i] - prices[start]);
        }

        return max_profit;
    }
};
