class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long current = accumulate(nums.begin(), nums.end(), 0LL);
        long long diff = abs(goal - current);
        return (int)ceil(((double)diff)/limit);
    }
};
