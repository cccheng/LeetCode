class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nr_row = grid.size();
        int nr_col = grid.front().size();
        vector<int> dp(nr_col);

        dp[0] = grid[0][0];
        for (int c = 1; c < nr_col; ++c)
            dp[c] = dp[c-1] + grid[0][c];

        for (int r = 1; r < nr_row; ++r) {
            dp[0] += grid[r][0];
            for (int c = 1; c < nr_col; ++c) {
                dp[c] = grid[r][c] + min(dp[c-1], dp[c]);
            }
        }

        return dp.back();
    }
};
