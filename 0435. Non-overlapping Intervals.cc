class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ints) {
        if (ints.size() <= 1)
            return 0;

        sort(ints.begin(), ints.end(),
             [](const auto& a, const auto& b) {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
             }
            );

        int count = 0;
        vector<vector<int>> result;
        result.push_back(ints[0]);
        for (int i = 1; i < ints.size(); ++i) {
            if (result.back()[1] > ints[i][0]) {
                count++;
                result.back()[1] = min(result.back()[1], ints[i][1]);
            } else {
                result.push_back(ints[i]);
            }
        }
        return count;
    }
};
