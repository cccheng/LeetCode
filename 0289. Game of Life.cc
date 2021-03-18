class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int nr_row = board.size();
        int nr_col = board.front().size();

        function<bool(int,int)> valid = [&](int r, int c) -> bool {
            return !(r < 0 || c < 0 || r >= nr_row || c >= nr_col);
        };
        function<int(int,int)> popcount = [&](int r, int c) -> int {
            int dir[] = {-1,0,1};
            int count = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (i == 1 && j == 1)
                        continue;
                    if (valid(r+dir[i], c+dir[j]) && (board[r+dir[i]][c+dir[j]] & 1))
                        count++;
                }
            }
            return count;
        };

        for (int r = 0; r < nr_row; ++r) {
            for (int c = 0; c < nr_col; ++c) {
                int nb = popcount(r,c);
                if (board[r][c] & 1) {
                    if (nb == 2 || nb == 3)
                        board[r][c] |= 1 << 1;
                } else {
                    if (nb == 3)
                        board[r][c] |= 1 << 1;
                }
            }
        }
        for (int r = 0; r < nr_row; ++r) {
            for (int c = 0; c < nr_col; ++c) {
                board[r][c] >>= 1;
            }
        }
    }
};
