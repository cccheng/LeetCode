class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int nr_row = matrix.size();
        int nr_col = matrix.front().size();
        vector<vector<int>> steps = vector<vector<int>>(nr_row, vector<int>(nr_col, -1));
        vector<vector<bool>> candidate(nr_row, vector<bool>(nr_col, true));

        int mx = 0;
        int dir_r[] = {1, -1, 0, 0};
        int dir_c[] = {0, 0, 1, -1};

        function<void(int,int,int)> dfs = [&](int r, int c, int l) {
            candidate[r][c] = false;

            if (steps[r][c] != -1 && l < steps[r][c])
                return;

            steps[r][c] = l;
            mx = max(mx, l);

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir_r[i];
                int nc = c + dir_c[i];
                if (nr < 0 || nc < 0) continue;
                if (nr >= nr_row || nc >= nr_col) continue;
                if (matrix[r][c] >= matrix[nr][nc]) continue;
                dfs(nr, nc, l+1);
            }

        };

        typedef tuple<int,int,int> iii;
        priority_queue<iii, vector<iii>, greater<iii>> pq;
        for (int r = 0; r < nr_row; ++r) {
            for (int c = 0; c < nr_col; ++c) {
                pq.push({matrix[r][c], r, c});
            }
        }

        while (!pq.empty()) {
            auto [_, r, c] = pq.top();
            pq.pop();
            if (candidate[r][c]) {
                dfs(r, c, 1);
            }
        }

        return mx;
    }
};
