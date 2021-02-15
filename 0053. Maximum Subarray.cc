// v1 Kadane's algorithm
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

// v2 DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> table(nums.size());

        table[0] = nums[0];
        int result = table[0];

        for (int i = 1; i < table.size(); ++i) {
            table[i] = nums[i] + (table[i-1] < 0 ? 0 : table[i-1]);
            result = max(result, table[i]);
        }

        return result;
    }
};
