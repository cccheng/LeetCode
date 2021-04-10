class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int nr = nums.size();
        int result = 0;
        int sum = 0;
        unordered_map<int,int> count;

        count[0] = 1; // for subarray from 0

        for (int i = 0; i < nr; ++i) {
            sum += nums[i];
            result += count[sum - k];
            count[sum]++; // should be here to avoid count itself
        }

        return result;
    }
};
