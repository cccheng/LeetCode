class Solution {
    int count_vowels(string& str, int begin, int end) {
        int cnt = 0;

        for (int i = begin; i < end; ++i) {
            char c = str[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                cnt++;
            }
        }

        return cnt;
    }
public:
    bool halvesAreAlike(string s) {
        return count_vowels(s, 0, s.size()/2) == count_vowels(s, s.size()/2, s.size());
    }
};
