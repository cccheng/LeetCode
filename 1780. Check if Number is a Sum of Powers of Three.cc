class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> pre(15);

        for (int i = 0; i < pre.size(); ++i)
            pre[i] = pow(3, i);

        for (int i = pre.size() - 1; i >= 0; --i) {
            if (pre[i] <= n)
                n -= pre[i];
        }

        return n == 0;
    }
};
