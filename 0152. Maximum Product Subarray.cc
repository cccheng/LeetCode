class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> mx(nums.size());
        vector<int> mn(nums.size());
        int result = mx[0] = mn[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            mx[i] = max({nums[i], nums[i] * mx[i-1], nums[i] * mn[i-1]});
            mn[i] = min({nums[i], nums[i] * mx[i-1], nums[i] * mn[i-1]});
            result = max(result, mx[i]);
        }
        return result;
    }
};
