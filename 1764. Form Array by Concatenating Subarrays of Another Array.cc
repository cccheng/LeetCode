class Solution {
public:
    int find_subarray(vector<int>& target, vector<int>& nums, int offset) {
        int i;

        for (int start = offset; start < nums.size(); start++) {
            for (i = 0; i < target.size(); i++) {
                if (start + i >= nums.size())
                    break;
                if (target[i] != nums[start + i]) {
                    break;
                }
                if (i == target.size() - 1)
                    return start + target.size();
            }
        }

        return -1;
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int last = 0;
        for (auto v : groups) {
            last = find_subarray(v, nums, last);
            if (last == -1)
                return false;
        }
        return true;
    }
};
