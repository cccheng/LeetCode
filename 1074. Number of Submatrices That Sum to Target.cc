class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int nr_row = matrix.size();
        int nr_col = matrix.front().size();
        vector<vector<int>> presum(nr_row+1, vector<int>(nr_col+1));

        for (int r = 1; r <= nr_row; ++r) {
            for (int c = 1; c <= nr_col; ++c) {
                presum[r][c] = matrix[r-1][c-1] + presum[r-1][c] + presum[r][c-1] - presum[r-1][c-1];
            }
        }

        int count = 0;
        for (int r = 1; r <= nr_row; ++r) {
            for (int c = 1; c <= nr_col; ++c) {
                for (int rr = r; rr <= nr_row; ++rr) {
                    for (int cc = c; cc <= nr_col; ++cc) {
                        int s = presum[rr][cc] - presum[r-1][cc] - presum[rr][c-1] + presum[r-1][c-1];
                        if (s == target)
                            count++;
                    }
                }
            }
        }
        return count;
    }
};
