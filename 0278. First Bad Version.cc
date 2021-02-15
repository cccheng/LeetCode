// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int m;

        while (left < right) {
            m = left + (right - left) / 2;
            if(isBadVersion(m))
                right = m;
            else
                left = m + 1;
        }
        return left;
    }
};
