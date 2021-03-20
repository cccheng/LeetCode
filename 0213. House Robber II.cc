class Solution {
public:
    int rob(vector<int>& nums) {
        int mx1 = 0, mx2 = 0;
        int pre2, pre1, cur;

        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        pre2 = nums[0], pre1 = max(pre2, nums[1]);
        mx1 = max(pre2, pre1);
        for (int i = 2; i < nums.size() - 1; ++i) {
            cur = max(pre2 + nums[i], pre1);
            mx1 = max(cur, mx1);
            pre2 = pre1;
            pre1 = cur;
        }

        pre2 = nums[1], pre1 = max(pre2, nums[2]);
        mx2 = max(pre2, pre1);
        for (int i = 3; i < nums.size(); ++i) {
            cur = max(pre2 + nums[i], pre1);
            mx2 = max(cur, mx2);
            pre2 = pre1;
            pre1 = cur;
        }

        return max(mx1, mx2);
    }
};
