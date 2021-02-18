class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        
        int len = 1, next = len;
        while (next < nums.size()) {
            if (nums[len - 1] != nums[next]) {
                swap(nums[len], nums[next]);
                len++;
            }
            next++;
        }
        return len;
    }
};
