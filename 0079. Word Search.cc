class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        vector<vector<bool>> visited(board.size(),
                                     vector<bool>(board.back().size(), false));

        function<void(int,int,int)> dfs = [&](int row, int col, int offset) {
            if (row < 0 || row >= board.size() ||
                col < 0 || col >= board[row].size())
                return;

            if (found || visited[row][col])
                return;

            if (board[row][col] != word[offset])
                return;

            if (offset == word.size() - 1) {
                found = true;
                return;
            }

            visited[row][col] = true;
            dfs(row-1, col+0, offset+1);
            dfs(row+0, col-1, offset+1);
            dfs(row+0, col+1, offset+1);
            dfs(row+1, col+0, offset+1);
            visited[row][col] = false;
        };

        for (int row = 0; row < board.size(); ++row)
            for (int col = 0; col < board[row].size(); ++col)
                if (board[row][col] == word[0])
                    dfs(row, col, 0);

        return found;
    }
};
