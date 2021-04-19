class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;

        function<void(int,int,int,vector<int>&)> dfs = [&](int level, int begin, int sum, vector<int>& comb) {
            if (level == k) {
                if (sum == n)
                    result.push_back(comb);
                return;
            }

            for (int i = begin; i <= 9; ++i) {
                if (sum + i > n)
                    break;
                comb.push_back(i);
                dfs(level+1, i+1, sum+i, comb);
                comb.pop_back();
            }
        };

        vector<int> comb;
        dfs(0, 1, 0, comb);

        return result;
    }
};
