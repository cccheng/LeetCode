class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        function<void(int,vector<int>)> bt = [&](int offset, vector<int> cur) -> void {
            result.push_back(cur);

            if (offset >= n)
                return;

            for (int i = offset, j; i < n; ) {
                cur.push_back(nums[i]);
                bt(i + 1, cur);
                cur.pop_back();

                for (j = i+1; j < n && nums[i] == nums[j]; ++j)
                    ;
                i = j;
            }
        };

        bt(0, {});

        return result;
    }
};
