class Solution {
public:
    int mySqrt(int x) {
        uint64_t ret = x;
        while (ret*ret > x) {
            ret = (ret + x / ret) / 2;
        }
        return ret;
    }
};
