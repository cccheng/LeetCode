class Solution {
public:
    int countSubstrings(string s) {
        int nr = s.size();
        int count = 0;
        vector<vector<bool>> memo(nr, vector<bool>(nr, false));

        for (int i = 0; i < nr; ++i) {
            memo[i][i] = true;
            count++;
        }

        for (int l = 0; l < nr-1; ++l) {
            if (s[l] == s[l+1]) {
                memo[l][l+1] = true;
                count++;
            }
        }

        for (int len = 2; len < nr; ++len) {
            for (int l = 0; l + len < nr; ++l) {
                int r = l + len;
                if (s[l] == s[r] && memo[l+1][r-1]) {
                    memo[l][r] = true;
                    count++;
                }
            }
        }

        return count;
    }
};
