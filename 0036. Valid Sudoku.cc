class Solution {
public:
    bool is_repeat(const vector<char>& array) {
        vector<bool> shown(10, false);
        
        for (auto c : array) {
            if (c == '.')
                continue;
            if (shown[c - '0'])
                return true;
            shown[c - '0'] = true;
        }
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto& v : board)
            if (is_repeat(v))
                return false;
        for (int col = 0; col < 9; ++col) {
            vector<char> vec(9);
            for (int row = 0; row < 9; ++row)
                vec[row] = board[row][col];
            if (is_repeat(vec))
                return false;
        }
        vector<pair<int,int>> corner = {
            {0,0}, {0,3}, {0,6},
            {3,0}, {3,3}, {3,6},
            {6,0}, {6,3}, {6,6}
        };
        for (auto c : corner) {
            vector<char> vec;
            vec.push_back(board[c.first+0][c.second+0]);
            vec.push_back(board[c.first+0][c.second+1]);
            vec.push_back(board[c.first+0][c.second+2]);
            vec.push_back(board[c.first+1][c.second+0]);
            vec.push_back(board[c.first+1][c.second+1]);
            vec.push_back(board[c.first+1][c.second+2]);
            vec.push_back(board[c.first+2][c.second+0]);
            vec.push_back(board[c.first+2][c.second+1]);
            vec.push_back(board[c.first+2][c.second+2]);
            if (is_repeat(vec))
                return false;
        }
        return true;
    }
};
