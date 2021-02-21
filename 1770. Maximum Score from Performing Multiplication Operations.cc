class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        vector<vector<int>> memo(1001, vector<int>(1001, numeric_limits<int>::min()));

        function<int(int,int)> dp = [&](int offset, int left) -> int {
            if (offset >= mul.size())
                return 0;

            if (memo[offset][left] != numeric_limits<int>::min())
                return memo[offset][left];

            int right = nums.size() - offset + left - 1;
            int left_picked = mul[offset]*nums[left] + dp(offset + 1, left + 1);
            int right_picked = mul[offset]*nums[right] + dp(offset + 1, left);
            memo[offset][left] = max(left_picked, right_picked);

            return memo[offset][left];
        };

        return dp(0, 0); // offset, left
    }
};
