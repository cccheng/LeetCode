class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> table(nums.size(), false);

        table[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            if (table[i]) {
                for (int step = 1; i + step < nums.size() && step <= nums[i]; ++step)
                    table[i + step] = true;
            }
        }

        return table.back();
    }
};
