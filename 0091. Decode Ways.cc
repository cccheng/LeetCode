class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.size());

        if (s.empty() || s[0] == '0')
            return 0;
        if (s.size() == 1)
            return 1;

        memo[0] = 1;
        if (s[0] == '1')
            memo[1] = 1;
        else if (s[0] == '2' && s[1] >= '0' && s[1] <= '6')
            memo[1] = 1;
        if (s[1] != '0')
            memo[1] += 1;

        for (int i = 2; i < s.size(); ++i) {
            if (s[i-1] == '1')
                memo[i] += memo[i-2];
            else if (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6')
                memo[i] += memo[i-2];
            if (s[i] != '0')
                memo[i] += memo[i-1];
        }

        return memo.back();
    }
};
