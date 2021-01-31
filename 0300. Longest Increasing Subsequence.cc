class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> table(nums.size(), 1);
        int LIS = 1;
        for (auto i = 1; i < table.size(); ++i) {
            for (auto j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    table[i] = max(table[i], table[j] + 1);
                    LIS = max(LIS, table[i]);
                }
            }
        }

        return LIS;
    }
};
