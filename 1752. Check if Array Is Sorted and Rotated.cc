class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        
        if (nums.size() < 2)
            return true;
        
        if (nums[0] < nums.back())
            count++;
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i-1])
                count++;
            if (count >= 2)
                break;
        }
        
        return count < 2;
    }
};
