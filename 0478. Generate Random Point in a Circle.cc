class Solution {
private:
    double ra;
    double xc;
    double yc;
public:
    Solution(double radius, double x_center, double y_center) {
        ra = radius;
        xc = x_center;
        yc = y_center;
    }

    vector<double> randPoint() {
        double degree = (double)rand() / RAND_MAX * 2 * M_PI;
        double l = sqrt((double)rand() / RAND_MAX) * ra;

        return {xc + l * cos(degree), yc + l * sin(degree)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
