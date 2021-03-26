class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        if (nums.empty())
            return 0;
        
        int mx = 1;
        int cur = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1]+1 == nums[i]) {
                cur++;
                mx = max(mx, cur);
            } else if (nums[i-1] != nums[i] ){
                cur = 1;
            }
        }
        
        return mx;
    }
};
