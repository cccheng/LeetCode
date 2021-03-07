class Solution {
public:
    int distance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_index = -1;
        int minimum = numeric_limits<int>::max();

        vector<int> dis(points.size(), -1);
        for (int i = 0; i < points.size(); ++i) {
            if (points[i][0] == x || points[i][1] == y) {
                dis[i] = distance(x, y, points[i][0], points[i][1]);
                if (dis[i] < minimum) {
                    min_index = i;
                    minimum = dis[i];
                }
            }
        }

        return min_index;
    }
};
