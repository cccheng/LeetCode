class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums;

        sort(nums.begin(), nums.end());

        int mx = 1, mx_idx = 0;;
        vector<int> memo(nums.size(), 1);
        vector<int> pre_idx(nums.size(), -1);
        for (int i = 1; i < memo.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] % nums[j] != 0)
                    continue;

                if (memo[j] + 1 > memo[i]) {
                    memo[i] = memo[j] + 1;
                    pre_idx[i] = j;
                }

                if (memo[i] > mx) {
                    mx = memo[i];
                    mx_idx = i;
                }
            }
        }

        vector<int> result;
        for (int i = mx_idx; i != -1; i = pre_idx[i]) {
            result.push_back(nums[i]);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
