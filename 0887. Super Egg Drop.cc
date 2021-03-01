class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp = vector(K+1, vector<int>(N+1));

        for (int n = 1; n <= N; ++n)
            dp[1][n] = n;
        for (int k = 1; k <= K; ++k)
            dp[k][1] = 1;

        for (int k = 2; k <= K; ++k) {
            for (int n = 2; n <= N; ++n) {
                int ret = numeric_limits<int>::max();
                //for (int i = 2; i <= n; ++i)
                //    ret = min(ret, 1+ max(dp[k][n-i], dp[k-1][i-1]));
                int low = 2, high = n, middle;
                int broken, unbroken;
                while (low <= high) {
                    middle = low + (high-low) / 2;
                    broken = dp[k-1][middle-1];
                    unbroken = dp[k][n-middle];
                    if (broken > unbroken) {
                        high = middle - 1;
                        ret = min(ret, broken + 1);
                    } else {
                        low = middle + 1;
                        ret = min(ret, unbroken + 1);
                    }
                }

                dp[k][n] = ret;
            }
        }

        return dp[K][N];
    }
};
