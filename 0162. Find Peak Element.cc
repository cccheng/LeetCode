class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i;

        for (i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] <= nums[i - 1])
                continue;
            if (i != nums.size() - 1 && nums[i] <= nums[i + 1])
                continue;
            return i;
        }

        return 0;
    }
};
