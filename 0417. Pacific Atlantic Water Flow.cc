class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
            return {};

        int nr_row = matrix.size();
        int nr_col = matrix.front().size();
        vector<vector<int>> dir = {{1,0},{-1,0}, {0,1}, {0,-1}};
        vector<vector<int>> memo(nr_row, vector<int>(nr_col)); // 1: pacific, 2: atlantic

        function<bool(int,int)> is_valid = [&](int r, int c) -> bool {
            return !(r < 0 || c < 0 || r >= nr_row || c >= nr_col);
        };

        queue<pair<int,int>> que;
        for (int i = 0; i < nr_col; ++i) { que.push({0, i}); memo[0][i] |= 1; }
        for (int i = 0; i < nr_row; ++i) { que.push({i, 0}); memo[i][0] |= 1; }
        while (!que.empty()) {
            auto [r, c] = que.front(); que.pop();
            for (int i = 0; i < dir.size(); ++i) {
                int _r = r + dir[i][0];
                int _c = c + dir[i][1];
                if (!is_valid(_r, _c))
                    continue;
                if (matrix[r][c] > matrix[_r][_c] || memo[_r][_c] & 1)
                    continue;
                memo[_r][_c] |= 1;
                que.push({_r, _c});
            }
        }

        for (int i = 0; i < nr_col; ++i) { que.push({nr_row-1, i}); memo[nr_row-1][i] |= 2; }
        for (int i = 0; i < nr_row; ++i) { que.push({i, nr_col-1}); memo[i][nr_col-1] |= 2; }
        while (!que.empty()) {
            auto [r, c] = que.front(); que.pop();
            for (int i = 0; i < dir.size(); ++i) {
                int _r = r + dir[i][0];
                int _c = c + dir[i][1];
                if (!is_valid(_r, _c))
                    continue;
                if (matrix[r][c] > matrix[_r][_c] || memo[_r][_c] & 2)
                    continue;
                memo[_r][_c] |= 2;
                que.push({_r, _c});
            }
        }

        vector<vector<int>> result;
        for (int r = 0; r < nr_row; ++r) {
            for (int c = 0; c < nr_col; ++c) {
                if (memo[r][c] == 3)
                    result.push_back({r, c});
            }
        }

        return result;
    }
};
