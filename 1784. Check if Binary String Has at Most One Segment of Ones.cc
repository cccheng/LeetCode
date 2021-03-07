class Solution {
public:
    bool checkOnesSegment(string s) {
        bool one = false;
        int count = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (one) continue;
                one = true;
                count++;
                if (count > 1) return false;
            } else {
                one = false;
            }
        }
        return count == 1;
    }
};
