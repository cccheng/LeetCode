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
