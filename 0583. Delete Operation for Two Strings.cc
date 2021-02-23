class Solution {
public:
    int minDistance(string word1, string word2) {
        int nr_row = word1.size();
        int nr_col = word2.size();
        vector<vector<int>> table(nr_row+1, vector<int>(nr_col+1, 0));

        for (int r = 1; r <= nr_row; ++r) {
            for (int c = 1; c <= nr_col; ++c) {
                table[r][c] = max({
                    table[r][c-1],
                    table[r-1][c]
                });

                if (word1[r-1] == word2[c-1])
                    table[r][c] = max(table[r][c], table[r-1][c-1]+1);
            }
        }

        int lcs_size = table[nr_row][nr_col];

        return word1.size() + word2.size() - 2*lcs_size;
    }
};
