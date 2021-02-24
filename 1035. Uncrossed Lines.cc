class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int nr_row = A.size();
        int nr_col = B.size();
        vector<vector<int>> table(nr_row+1, vector<int>(nr_col+1, 0));

        for (int r = 1; r <= nr_row; ++r) {
            for (int c = 1; c <= nr_col; ++c) {
                if (A[r-1] == B[c-1])
                    table[r][c] = table[r-1][c-1] + 1;
                else
                    table[r][c] = max(table[r][c-1], table[r-1][c]);
            }
        }

        return table[nr_row][nr_col];
    }
};
