class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int buy_i = 0;

        for (auto i = 0; i < prices.size(); ++i) {
            if (prices[i] < prices[buy_i])
                buy_i = i;
            result = max(prices[i] - prices[buy_i], result);
        }

        return result;
    }
};

// v2. DP. similar to 0122
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;

        if (prices.empty())
            return mx;

        int buy = -prices[0];
        int sold = 0;

        for (int i = 1; i < prices.size(); ++i) {
            int _buy = max(buy, -prices[i]);
            int _sold = max(sold, buy + prices[i]);
            buy = _buy;
            sold = _sold;
            mx = max({mx, buy, sold});
        }

        return mx;
    }
};
