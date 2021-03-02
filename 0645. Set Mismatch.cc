class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int repeat, loss, n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; ++i)
            if (nums[i] == nums[i+1])
                repeat = nums[i];

        loss = (n * (n + 1) / 2) - accumulate(nums.begin(), nums.end(), 0) + repeat;

        return {repeat, loss};
    }
};
