class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        int col = 0;

        while (row >= 0 && col < matrix.front().size()) {
            if (matrix[row][col] > target)
                row--;
            else if (matrix[row][col] < target)
                col++;
            else
                return true;
        }

        return false;
    }
};

// v2
class Solution {
public:
    bool _search(vector<vector<int>>& m, int v, int rbegin, int rend, int cbegin, int cend) {
        if (rbegin + 1 >= rend && cbegin + 1 >= cend)
            return m[rbegin][cbegin] == v;

        int rmid = rbegin + (rend - rbegin) / 2;
        int cmid = cbegin + (cend - cbegin) / 2;

        if (m[rmid][cmid] == v)
            return true;
        else if (m[rmid][cmid] > v) {
            return _search(m, v, rbegin, rmid, cbegin, cmid) ||
                _search(m, v, rmid, rend, cbegin, cmid) ||
                _search(m, v, rbegin, rmid, cmid, cend);
        } else {
            return _search(m, v, rmid, rend, cmid, cend) ||
                _search(m, v, rmid, rend, cbegin, cmid) ||
                _search(m, v, rbegin, rmid, cmid, cend);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return _search(matrix, target, 0, matrix.size(), 0, matrix.front().size());
    }
};
