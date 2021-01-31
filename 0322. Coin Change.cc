class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> table(amount + 1);

        table[0] = 0;
        for (auto i = 1; i < table.size(); ++i) {
            table[i] = -1;
            for (auto c : coins) {
                if (i - c < 0 || table[i - c] == -1)
                    continue;
                if (table[i] == -1 || table[i] > table[i - c] + 1)
                    table[i] = table[i - c] + 1;
            }
        }

        return table[amount];
    }
};
