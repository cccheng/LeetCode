class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> steps(nums.size(), numeric_limits<int>::max());

        steps[0] = 0;
        for (int i = 0 ; i < nums.size(); ++i) {
            if (steps[i] == numeric_limits<int>::max())
                continue;
            if (i != 0 && nums[i-1] - nums[i] >= 1)
                continue;
            for (int s = 1; s <= nums[i]; ++s) {
                if (i + s >= nums.size())
                    break;
                steps[i+s] = min(steps[i+s], steps[i] + 1);
            }
        }

        return steps.back();
    }
};
