class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto convert = [&](int n) -> pair<int,int> {
            return make_pair(n / matrix.front().size(), n % matrix.front().size());
        };

        int left = 0, right = matrix.size() * matrix.front().size() - 1;
        int middle;
        while (left <= right) {
            middle = left + (right - left) / 2;
            auto e = convert(middle);
            auto v = matrix[e.first][e.second];

            if (target < v)
                right = middle - 1;
            else if (target > v)
                left = middle + 1;
            else
                return true;
        }
        return false;
    }
};
