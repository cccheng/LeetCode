class Solution {
public:
    int getSum(int a, int b) {
        int result = 0;
        int carry = 0;

        while (b != 0) {
            result = a ^ b;
            carry = a & b;
            a = result;
            b = ((unsigned int)carry) << 1;
        }
        return result;
    }
};
