class Solution {
public:
    pair<int,int> count(string& str) {
        int count = 0;
        for (auto c : str) {
            if (c == '1') count++;
        }
        return {str.size() - count, count};
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> input; // <zero,one>
        for (auto s : strs)
            input.push_back(count(s));

        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        memo[0][0] = 0;
        int mx = 0;
        for (auto i : input) {
            for (int z = m; z >= 0; --z) {
                for (int o = n; o >= 0; --o) {
                    if (memo[z][o] < 0)
                        continue;
                    if (z + i.first <= m && o + i.second <= n) {
                        memo[z+i.first][o+i.second] = max(memo[z+i.first][o+i.second], memo[z][o] + 1);
                        mx = max(mx, memo[z+i.first][o+i.second]);
                    }
                }
            }
        }

        return mx;
    }
};
