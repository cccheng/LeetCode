class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nr = arr.size();
        vector<int> del1(nr);
        vector<int> del0(nr);

        if (arr.empty())
            return 0;

        del1[0] = 0;
        del0[0] = arr[0];

        int mx = arr[0];
        for (int i = 1; i < nr; ++i) {
            del0[i] = max({arr[i], del0[i-1] + arr[i]});
            del1[i] = max({del0[i-1], del1[i-1] + arr[i]});

            mx = max({mx, del0[i], del1[i]});
        }

        return mx;
    }
};
