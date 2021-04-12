class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);

        int l = 1, r = k+1;
        for (int i = 0; i <= k; ++i)
                res[i] = (i % 2) ? r-- : l++;

        for (int i = k+1; i < n; ++i)
            res[i] = i+1;

        return res;
    }
};
