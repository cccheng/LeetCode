class Solution {
public:
    int popcount(int n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int num) {
        vector<int> result(num+1);
        for (int i = 1; i < result.size(); ++i) {
            result[i] = popcount(i);
        }
        return result;
    }
};
