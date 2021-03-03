class Solution {
public:
    int lower_bound(vector<int>& vec, int target) {
        int l = 0;
        int r = vec.size();
        int m;
        
        while (l < r) {
            m = l + (r - l) / 2;
            
            if (vec[m] < target)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left, right;
        
        left = lower_bound(nums, target);
        
        if (left == nums.size() || nums[left] != target)
            return {-1, -1};
        
        right = lower_bound(nums, target + 1);
        
        return {left, right - 1};
    }
};
