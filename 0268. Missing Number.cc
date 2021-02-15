class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = (nums.size() * (nums.size() + 1)) / 2;
        return total - accumulate(nums.begin(), nums.end(), 0);
    }
};
