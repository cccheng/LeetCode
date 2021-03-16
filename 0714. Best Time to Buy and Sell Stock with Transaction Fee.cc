class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int mx = 0;
        vector<int> buy(prices.size());
        vector<int> sold(prices.size());

        if (prices.empty())
            return 0;

        buy[0] = -prices[0];
        sold[0] = 0;
        mx = max(buy[0], sold[0]);

        for (int i = 1; i < prices.size(); ++i) {
            buy[i] = max(buy[i-1], sold[i-1] - prices[i]);
            sold[i] = max(sold[i-1], buy[i-1] + prices[i] - fee);
            mx = max({mx, buy[i], sold[i]});
        }

        return mx;
    }
};
