class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        sort(candidates.begin(), candidates.end());

        function<void(int,int,vector<int>)> dfs = [&](int target, int idx, vector<int> items) {
            if (target == 0) {
                result.emplace_back(items);
                return;
            }

            for (int i = idx; i < candidates.size(); ++i) {
                if (candidates[i] > target)
                    break;
                items.emplace_back(candidates[i]);
                dfs(target - candidates[i], i, items);
                items.pop_back();
            }
        };

        dfs(target, 0, {});

        return result;
    }
};
