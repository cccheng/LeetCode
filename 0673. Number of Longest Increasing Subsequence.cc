class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        if (nums.empty())
            return 0;

        int mx = 1;
        vector<int> memo(nums.size(), 1);
        vector<int> count(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    if (memo[j] + 1 > memo[i]) {
                        memo[i] = memo[j] + 1;
                        count[i] = count[j];
                    } else if (memo[j] + 1 == memo[i]) {
                        count[i] += count[j];
                    }
                    mx = max(mx, memo[i]);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < count.size(); ++i)
            if (memo[i] == mx)
                result += count[i];

        return result;
    }
};
