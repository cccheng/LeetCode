class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ints) {
        int count = 0;

        sort(ints.begin(), ints.end(), [](auto& a, auto&b) {
            return a[1] < b[1];
        });

        for (auto i = 0; i < ints.size(); ) {
            int j = i + 1;
            while (j < ints.size() && ints[j][0] < ints[i][1]) {
                j++; count++;
            }
            i = j;
        }

        return count;
    }
};
