class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int result = 0;
        int min_sum = 0, max_sum = 0;
        for (auto n : nums) {
            max_sum = max(max_sum + n, n);
            min_sum = min(min_sum + n, n);
            result = max({result, max_sum, -min_sum});
        }
        return result;
    }
};
