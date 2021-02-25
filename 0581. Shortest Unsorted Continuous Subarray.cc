class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums.begin(), nums.end());

        sort(sorted.begin(), sorted.end());

        int i, stable = 0;
        for (i = 0; i < sorted.size(); ++i) {
            if (nums[i] == sorted[i])
                stable++;
            else
                break;
        }

        if (i != sorted.size()) {
            for (i = sorted.size() - 1; i >= 0; --i) {
                if (nums[i] == sorted[i])
                    stable++;
                else
                    break;
            }
        }

        return nums.size() - stable;
    }
};
