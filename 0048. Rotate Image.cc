class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());

        for (int row = 0; row < matrix.size(); ++row)
            for (int col = row + 1; col < matrix.size(); ++col)
                swap(matrix[row][col], matrix[col][row]);
    }
};
