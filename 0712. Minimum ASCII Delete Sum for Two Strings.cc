class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int nr_row = s1.size();
        int nr_col = s2.size();

        vector<vector<int>> table(nr_row + 1, vector<int>(nr_col + 1, 0));
        for (int r = 1; r <= nr_row; ++r)
            table[r][0] = table[r-1][0] + (int)s1[r-1];
        for (int c = 1; c <= nr_col; ++c)
            table[0][c] = table[0][c-1] + (int)s2[c-1];

        for (int r = 1; r <= nr_row; ++r) {
            for (int c = 1; c <= nr_col; ++c) {
                if (s1[r-1] == s2[c-1]) {
                    table[r][c] = table[r-1][c-1];
                } else {
                    table[r][c] = min({
                        table[r-1][c-1] + s1[r-1] + s2[c-1],
                        table[r-1][c] + s1[r-1],
                        table[r][c-1] + s2[c-1]});
                }
            }
        }

        return table[nr_row][nr_col];
    }
};
