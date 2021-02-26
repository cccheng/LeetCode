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

// v2
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_max = nums[0];
        int cur_min = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int _max = max({nums[i], nums[i] * cur_max, nums[i] * cur_min});
            int _min = min({nums[i], nums[i] * cur_max, nums[i] * cur_min});
            result = max(result, _max);
            cur_max = _max;
            cur_min = _min;
        }
        return result;
    }
};
