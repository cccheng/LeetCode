class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty())
            return 0;

        int max_area = 0;
        int cur_area = 0;
        auto nr_rows = grid.size();
        auto nr_cols = grid.front().size();

        function<void(int,int)> dfs = [&](int r, int c) -> void {
            if (c < 0 || r < 0 || c >= nr_cols || r >= nr_rows || grid[r][c] != 1)
                return;
            grid[r][c] = 0;
            cur_area++;
            dfs(r+1,c);
            dfs(r-1,c);
            dfs(r,c+1);
            dfs(r,c-1);
        };

        for (auto r = 0; r < nr_rows; r++)
            for (auto c = 0; c < nr_cols; c++) {
                if (grid[r][c] == 1) {
                    cur_area = 0;
                    dfs(r, c);
                    max_area = max(max_area, cur_area);
                }
            }

        return max_area;
    }
};
