class Solution {
public:
    int minDistance(string word1, string word2) {
        int nr_row = word1.size();
        int nr_col = word2.size();

        vector<vector<int>> table(nr_row + 1, vector<int>(nr_col + 1, 0));

        for (int r = 1; r <= nr_row; ++r)
            table[r][0] = r;
        for (int c = 1; c <= nr_col; ++c)
            table[0][c] = c;

        for (int r = 1; r <= nr_row; ++r) {
            for (int c = 1; c <= nr_col; ++c) {
                if (word1[r - 1] == word2[c - 1])
                    table[r][c] = table[r-1][c-1];
                else {
                    table[r][c] = min({
                        table[r-1][c-1],
                        table[r-1][c],
                        table[r][c-1]
                    }) + 1;
                }
            }
        }

        return table[nr_row][nr_col];
    }
};
