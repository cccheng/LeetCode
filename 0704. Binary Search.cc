class Solution {
public:
    int search(vector<int>& nums, int target) {
        int m, l = 0, r = nums.size();

        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }

        if (l != nums.size() && nums[l] == target)
            return l;
        else
            return -1;
    }
};
