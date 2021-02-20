class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(m, vector<int>(n, 0));
        table[0][0] = 1;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row - 1 >= 0)
                    table[row][col] += table[row-1][col];
                if (col - 1 >= 0)
                    table[row][col] += table[row][col-1];
            }
        }

        return table.back().back();
    }
};
