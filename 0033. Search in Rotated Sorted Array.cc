class Solution {
    int bsearch(vector<int>& nums, int l, int r, int target) {
        int m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }

    int rsearch(vector<int>& nums, int l, int r, int target) {
        if (l == r)
            return -1;
        if (l + 1 == r) {
            if (nums[l] == target)
                return l;
            else
                return -1;
        }

        int m = l + (r - l) / 2;
        int ret;
        if (nums[l] <= nums[m]) {
            ret = bsearch(nums, l, m, target);
            if (ret != m && nums[ret] == target)
                return ret;
            return rsearch(nums, m, r, target);
        } else {
            ret = bsearch(nums, m, r, target);
            if (ret != r && nums[ret] == target)
                return ret;
            return rsearch(nums, l, m, target);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return rsearch(nums, 0, nums.size(), target);
    }
};
