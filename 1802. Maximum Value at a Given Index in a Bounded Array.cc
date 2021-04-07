class Solution {
    bool possible(int n, int i, int maxSum, int m) {
        for (int d = 1; maxSum >= 0 && d < m && i + d < n; ++d)
            maxSum -= m - d;
        for (int d = 1; maxSum >= 0 && d < m && i - d >= 0; ++d)
            maxSum -= m - d;
        return maxSum >= 0;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 0, r = maxSum+1, m;

        while (l < r) {
            m = l + (r-l) / 2;

            if (possible(n, index, maxSum-n-m, m))
                l = m + 1;
            else
                r = m;
        }

        return l;
    }
};
