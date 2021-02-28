class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int max_bc = *max_element(baseCosts.begin(), baseCosts.end());
        int max_tc = *max_element(toppingCosts.begin(), toppingCosts.end());

        vector<bool> table(max_bc + 2*max_tc + 1);

        for (auto bc : baseCosts)
            table[bc] = true;

        for (auto tc : toppingCosts) {
            vector<bool> new_table(table);
            for (int i = 0; i < table.size(); ++i) {
                if (!table[i])
                    continue;
                if (i + tc < table.size())
                    new_table[i + tc] = true;
                if (i + tc + tc < table.size())
                    new_table[i + tc + tc] = true;
            }
            table.swap(new_table);
        }

        for (int i = 0; target - i >= 0 || target + i < table.size(); i++) {
            if (target - i >= 0 && table[target - i])
                return target - i;
            if (target + i < table.size() && table[target + i])
                return target + i;
        }
        return 0;
    }
};
