class Solution {
public:
    int countArrangement(int n) {
        int count = 0;
        vector<bool> used(n+1);

        function<void(int)> dfs = [&](int level) -> void {
            if (level > n) {
                count++;
            }

            for (int i = 1; i <= n; ++i) {
                if (used[i])
                    continue;
                if (i % level == 0 || level % i == 0) {
                    used[i] = true;
                    dfs(level + 1);
                    used[i] = false;
                }
            }
        };

        dfs(1);

        return count;
    }
};
