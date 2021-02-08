class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid.front().empty())
            return 0;

        int count = 0;
        auto nr_rows = grid.size();
        auto nr_cols = grid.front().size();

        function<void(int,int)> dfs = [&](int r, int c) -> void {
            if (c < 0 || c >= nr_cols || r < 0 || r >= nr_rows || grid[r][c] != '1')
                return;
            grid[r][c] = '0';

            dfs(r-1, c);
            dfs(r+1, c);
            dfs(r, c+1);
            dfs(r, c-1);
        };

        for (auto r = 0; r < nr_rows; r++)
            for (auto c = 0; c < nr_cols; c++)
                if (grid[r][c] == '1') {
                    dfs(r, c);
                    count++;
                }

        return count;
    }
};
