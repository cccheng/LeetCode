class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](auto c) { return !isalnum(c); }), s.end());
        for (int i = 0; i < s.size(); ++i)
            s[i] = tolower(s[i]);

        return s == string(s.rbegin(), s.rend());
    }
};
