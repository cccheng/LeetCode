class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board.front().empty())
            return;

        auto nr_rows = board.size();
        auto nr_cols = board.front().size();

        function<void(int,int)> dfs = [&](int r, int c) -> void {
            if (r < 0 || r >= nr_rows || c < 0 || c >= nr_cols || board[r][c] != 'O')
                return;
            board[r][c] = 'G';
            dfs(r+1,c);
            dfs(r-1,c);
            dfs(r,c+1);
            dfs(r,c-1);
        };

        for (auto i = 0; i < nr_rows; ++i)
            dfs(i, 0), dfs(i, nr_cols-1);
        for (auto i = 0; i < nr_cols; ++i)
            dfs(0, i), dfs(nr_rows-1, i);

        for (auto r = 0; r < nr_rows; r++)
            for (auto c = 0; c < nr_cols; c++) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                if (board[r][c] == 'G')
                    board[r][c] = 'O';
            }
    }
};
