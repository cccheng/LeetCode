class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<pair<int,int>> dir = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };

        int row = 0, col = 0, cur_dir = 0;
        int count = matrix.size() * matrix.front().size();
        vector<int> result;

        auto valid = [&](int r, int c) -> bool {
            if (r < 0 || c < 0)
                return false;
            if (r >= matrix.size() || c >= matrix.front().size())
                return false;
            if (matrix[r][c] == 1024)
                return false;
            return true;
        };

        while (count--) {
            result.emplace_back(matrix[row][col]);
            matrix[row][col] = 1024;

            int nr = row + dir[cur_dir % 4].first;
            int nc = col + dir[cur_dir % 4].second;
            while (count && !valid(nr, nc)) {
                cur_dir++;
                nr = row + dir[cur_dir % 4].first;
                nc = col + dir[cur_dir % 4].second;
            }

            row = nr;
            col = nc;
        }

        return result;
    }
};
