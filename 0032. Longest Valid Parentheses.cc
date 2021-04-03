class Solution {
public:
    int longestValidParentheses(string s) {
        int nr = s.size();
        vector<int> rpair(nr, -1);

        if (nr < 2)
            return 0;

        for (int left = nr-1; left >= 0; --left) {
            for (int right = left+1; right < nr; ++right) {
                if (s[right-1] == '(' && s[right] == ')') {
                    rpair[right-1] = right;
                } else if (s[left] == '(' && s[right] == ')') {
                    int i;
                    for (i = left+1; i < nr && rpair[i] != -1; i = rpair[i]+1)
                        ;
                    if (i == right) {
                        rpair[left] = right;
                    }
                }
            }
        }

        int mx = 0;
        for (int cur = 0; cur < nr; cur++) {
            int cur_mx = 0;
            while (cur < nr && rpair[cur] != -1) {
                cur_mx += rpair[cur] - cur + 1;
                cur = rpair[cur] + 1;
            }
            mx = max(mx, cur_mx);
        }

        return mx;
    }
};
