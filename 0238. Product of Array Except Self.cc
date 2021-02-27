class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        vector<int> result(nums.size());
        
        for (int i = 0, product = 1 ; i < nums.size(); ++i) {
            product *= nums[i];
            left[i] = product;
        }
        for (int i = nums.size() - 1, product = 1; i >= 0; --i) {
            product *= nums[i];
            right[i] = product;
        }
        
        result[0] = right[1];
        if (nums.size() > 1)
            result.back() = left[nums.size()-2];
        for (int i = 1; i < nums.size() - 1; ++i) {
            result[i] = left[i-1] * right[i+1];
        }
        
        return result;
    }
};
