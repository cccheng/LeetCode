class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int nr = piles.size();
        vector<vector<int>> dp(nr, vector<int>(nr, numeric_limits<int>::min()));

        function<int(int,int)> score = [&](int l, int r) -> int {
            if (dp[l][r] != numeric_limits<int>::min())
                return dp[l][r];

            if (l == r)
                dp[l][r] = piles[l];
            else {
                dp[l][r] = max(piles[l] - score(l+1,r), piles[r] - score(l,r-1));
            }
            return dp[l][r];
        };

        score(0, nr-1);

        return dp[0][nr-1] > 0;
    }
};
