class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() <= 1)
            return triangle[0][0];

        for (int r = 1; r < triangle.size(); ++r) {
            triangle[r][0] += triangle[r-1][0];
            triangle[r][triangle[r].size() - 1] += triangle[r-1][triangle[r].size() - 2];
            for (int c = 1; c < triangle[r].size() - 1; ++c) {
                triangle[r][c] += min(triangle[r-1][c], triangle[r-1][c-1]);
            }
        }

        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};
