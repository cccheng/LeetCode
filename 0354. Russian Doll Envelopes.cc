class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        vector<int> lis(env.size(), 1);

        sort(env.begin(), env.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });
        for (int i = 0; i < lis.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (env[j][0] < env[i][0] && env[j][1] < env[i][1])
                    lis[i] = max(lis[i], lis[j]+1);
            }
        }

        return *max_element(lis.begin(), lis.end());
    }
};
