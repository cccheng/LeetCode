class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;

        if (prices.empty())
            return mx;

        int buy = -prices[0];
        int sold = 0;

        for (int i = 1; i < prices.size(); ++i) {
            int _buy = max(buy, sold - prices[i]);
            int _sold = max(sold, buy + prices[i]);
            buy = _buy;
            sold = _sold;
            mx = max({mx, buy, sold});
        }

        return mx;
    }
};
