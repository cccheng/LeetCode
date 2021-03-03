class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row_first_zero = false;
        bool column_first_zero = false;
        int nr_row = matrix.size();
        int nr_col = matrix.front().size();

        for (int r = 0; r < nr_row; ++r)
            if (matrix[r][0] == 0)
                column_first_zero = true;
        for (int c = 0; c < nr_col; ++c)
            if (matrix[0][c] == 0)
                row_first_zero = true;

        for (int r = 1; r < nr_row; ++r)
            for (int c = 1; c < nr_col; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }

        for (int r = 1; r < nr_row; ++r)
            if (matrix[r][0] == 0)
                for (int c = 1; c < nr_col; ++c)
                    matrix[r][c] = 0;
        for (int c = 1; c < nr_col; ++c)
            if (matrix[0][c] == 0)
                for (int r = 1; r < nr_row; ++r)
                    matrix[r][c] = 0;
        if (column_first_zero)
            for (int r = 0; r < nr_row; ++r)
                matrix[r][0] = 0;
        if (row_first_zero)
            for (int c = 0; c < nr_col; ++c)
                matrix[0][c] = 0;
    }
};
