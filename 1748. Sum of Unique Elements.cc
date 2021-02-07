class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        
        for (auto i = 0; i < nums.size(); ) {
            if (i + 1 >= nums.size()) {
                sum += nums[i];
                i++;
            } else if (nums[i] != nums[i+1]) {
                sum += nums[i];
                i++;
            } else {
                int next = i+1;
                while (next < nums.size() && nums[i] == nums[next])
                    next++;
                i = next;
            }
        }
        return sum;
    }
};
