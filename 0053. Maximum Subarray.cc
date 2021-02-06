class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = nums[0];
        int result = cur_sum;
        
        for (size_t i = 1; i < nums.size(); ++i) {
            if (cur_sum + nums[i] < nums[i])
                cur_sum = nums[i];
            else
                cur_sum = cur_sum + nums[i];
            result = max(cur_sum, result);
        }
        return result;
    }
};
