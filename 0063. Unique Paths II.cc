class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int nr_row = obstacleGrid.size();
        int nr_col = obstacleGrid.front().size();
        vector<vector<int>> memo(nr_row+1, vector<int>(nr_col+1));

        if (!obstacleGrid[0][0])
            memo[1][1] = 1;

        for (int r = 1; r <= nr_row; ++r) {
            for (int c = 1; c <= nr_col; ++c) {
                if (obstacleGrid[r-1][c-1])
                    continue;
                else
                    memo[r][c] += memo[r-1][c] + memo[r][c-1];
            }
        }

        return memo[nr_row][nr_col];
    }
};
