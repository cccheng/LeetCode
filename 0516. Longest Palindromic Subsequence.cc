class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<vector<int>> dp(N+1, vector<int>(N+1));

        // s[i] == s[j] ==> dp[i][j] = dp[i-1][j-1] + 2;
        // s[i] != s[j] ==> dp[i][j] = max(dp[i-1][j], d[i][j-1])

        for (int i = 1; i <= N; ++i)
            dp[i][i] = 1;
        for (int l = N; l >= 1; --l) {
            for (int r = l + 1; r <= N; ++r) {
                if (s[l-1] == s[r-1])
                    dp[l][r] = dp[l+1][r-1] + 2;
                else
                    dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            }
        }

        return dp[1][s.size()];
    }
};
