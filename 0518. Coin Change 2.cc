class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> table(amount + 1);

        sort(coins.begin(), coins.end());
        table[0] = 1;
        for (auto c : coins) {
            for (int i = 0; i < table.size(); ++i)
                if (i + c < table.size())
                    table[i + c] += table[i];
        }

        return table[amount];
    }
};
