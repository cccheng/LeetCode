class Solution {
public:
    int min(vector<int>& nums, int begin, int end) {
        if (end - begin == 1)
            return nums[begin];
        if (end - begin == 2)
            return ::min(nums[begin], nums[end-1]);

        if (nums[begin] <= nums[end-1])
            return nums[begin];

        int middle = begin + (end - begin) / 2;
        return ::min(min(nums, begin, middle), min(nums, middle, end));
    }
    int findMin(vector<int>& nums) {
        return min(nums, 0, nums.size());
    }
};
