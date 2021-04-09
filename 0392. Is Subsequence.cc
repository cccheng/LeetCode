class Solution {
    int bsearch(vector<int>& vec, int target) {
        int l = 0, r = vec.size(), m;

        while (l < r) {
            m = l + (r - l) / 2;
            if (vec[m] > target)
                r = m;
            else if (vec[m] < target)
                l = m + 1;
            else
                r = m;
        }

        return l;
    }

public:
    bool isSubsequence(string s, string t) {
        map<char,vector<int>> pos;

        for (int i = 0; i < t.size(); ++i) {
            pos[t[i]].push_back(i);
        }

        int cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            int idx = bsearch(pos[s[i]], cur);
            if (idx == pos[s[i]].size())
                return false;
            cur = pos[s[i]][idx] + 1;
        }

        return true;
    }
};
