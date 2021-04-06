class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<bool> used(n + 1);
        vector<vector<int>> result;

        function<void(int,int,vector<int>&)> dfs = [&](int offset, int begin, vector<int>& vec) {
            if (offset >= k) {
                result.push_back(vec);
                return;
            }
            for (int i = begin; i <= n; ++i) {
                if (used[i])
                    continue;

                vec[offset] = i;
                used[i] = true;
                dfs(offset+1, i+1, vec);
                used[i] = false;
            }
        };

        vector<int> tmp(k);
        dfs(0, 1, tmp);

        return result;
    }
};
