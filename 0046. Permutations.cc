class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> vec(nums.size());

        function<void(int)> dfs = [&](int offset) -> void {
            if (offset >= nums.size()) {
                result.push_back(vec);
                return;
            }

            for (auto i = 0; i < nums.size(); ++i) {
                if (used[i])
                    continue;
                vec[offset] = nums[i];
                used[i] = true;
                dfs(offset + 1);
                used[i] = false;
            }
        };

        dfs(0);

        return result;
    }
};

