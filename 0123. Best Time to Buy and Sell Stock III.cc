class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;

        if (prices.empty())
            return mx;

        int buy_1st = -prices[0];
        int buy_2nd = numeric_limits<int>::min();
        int sold_1st = 0;
        int sold_2nd = 0;

        for (int i = 1; i < prices.size(); ++i) {
            sold_2nd = max(sold_2nd, buy_2nd + prices[i]);
            buy_2nd = max(buy_2nd, sold_1st - prices[i]);
            sold_1st = max(sold_1st, buy_1st + prices[i]);
            buy_1st = max(buy_1st, -prices[i]);
            mx = max({mx, buy_1st, buy_2nd, sold_1st, sold_2nd});
        }

        return mx;
    }
};
