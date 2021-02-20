class Solution {
public:
    bool isNice(string& s, int left, int right) {
        vector<int> upper(30, 0);
        vector<int> lower(30, 0);
        for (int i = left; i <= right; ++i) {
            if (isupper(s[i]))
                upper[s[i] - 'A']++;
            else if (islower(s[i]))
                lower[s[i] - 'a']++;
        }
        for (int i = 0; i < upper.size(); ++i)
            if ((upper[i] != 0 && lower[i] == 0) || (upper[i] == 0 && lower[i] != 0))
                return false;
        return true;
    }

    string longestNiceSubstring(string s) {
        string result;
        int maxlen = 0;
        for (int left = 0; left < s.size(); left++) {
            for (int right = left + 1; right < s.size(); right++) {
                if (isNice(s, left, right)) {
                    if (right - left + 1 > maxlen) {
                        maxlen = right - left + 1;
                        result = s.substr(left, maxlen);
                    }
                }
            }
        }

        return result;
    }
};
