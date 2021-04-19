class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int64_t> dp(target + 1);

        dp[0] = 1;
        for (int i = 0; i <= target; ++i) {
            if (dp[i] > numeric_limits<int>::max())
                continue;
            for (auto n : nums) {
                if (i + n <= target)
                    dp[i+n] += dp[i];
            }
        }

        return dp[target];
    }
};
