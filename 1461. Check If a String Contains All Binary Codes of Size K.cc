class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k)
            return false;

        unordered_set<string> substr;
        for (int i = 0; i + k <= s.size(); ++i)
            substr.insert(s.substr(i, k));

        return substr.size() == pow(2, k);
    }
};
