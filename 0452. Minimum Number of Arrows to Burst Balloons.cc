class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0;

        sort(points.begin(), points.end(), [](auto& a, auto& b) -> bool {
           return a[1] < b[1];
        });

        for (int i = 0; i < points.size(); ) {
            int j = i + 1;
            while (j < points.size() && points[i][0] <= points[j][1] && points[j][0] <= points[i][1])
                count++, j++;
            i = j;
        }
        return points.size() - count;
    }
};
