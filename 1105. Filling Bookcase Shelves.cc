class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int nr = books.size();
        vector<int> height(nr, numeric_limits<int>::max());

        if (nr == 0)
            return 0;

        // 0: w, 1: h
        for (int i = 0; i < nr; ++i) {
            int w = 0, h = 0;
            for (int j = i; j >= 0; --j) {
                if (w + books[j][0] > shelf_width)
                    break;
                w += books[j][0];
                h = max(h, books[j][1]);
                height[i] = min(height[i], (j == 0 ? 0 : height[j-1]) + h);
            }
        }

        return height.back();
    }
};
