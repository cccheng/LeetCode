class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;

        vector<string> puzzle(n, string(n, '.'));

        function<bool(int,int)> isValid = [&](int row, int col) -> bool {
            for (int i = 0; i < n; ++i)
                if (puzzle[row][i] == 'Q' || puzzle[i][col] == 'Q')
                    return false;
            //check if the 45° diagonal had a queen before.
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
                if (puzzle[i][j] == 'Q')
                    return false;
            //check if the 135° diagonal had a queen before.
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
                if (puzzle[i][j] == 'Q')
                    return false;

            return true;
        };

        function<void(int,int)> bt = [&](int count, int offset) -> void {
            int row = offset / n;
            int col = offset % n;

            if (count == 0) {
                result.push_back(puzzle);
                return;
            }

            if (offset == n*n) {
                return;
            }

            if (count > 0 && isValid(row, col)) {
                puzzle[row][col] = 'Q';
                bt(count - 1, offset + 1);
                puzzle[row][col] = '.';
            }
            bt(count, offset + 1);
        };

        bt(n, 0);

        return result;
    }
};
