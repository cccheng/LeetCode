class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 && carry != 0; --i) {
            if (digits[i] + carry >= 10) {
                digits[i] = 0;
            } else {
                digits[i]++;
                carry = 0;
                break;
            }
        }
        
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
