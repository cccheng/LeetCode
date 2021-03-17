class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;
        int nr = prices.size();
        vector<int> buy(nr);
        vector<int> sold(nr);
        vector<int> cool(nr);

        buy[0] = -prices[0];
        sold[0] = 0;
        cool[0] = 0;

        for (int i = 1; i < nr; ++i) {
            buy[i] = max(buy[i-1], cool[i-1] - prices[i]);
            sold[i] = max({cool[i-1], sold[i-1], buy[i-1] + prices[i]});
            cool[i] = max(cool[i-1], sold[i-1]);
            mx = max({buy[i], sold[i], cool[i]});
        }
        return mx;
    }
};
