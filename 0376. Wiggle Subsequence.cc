class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int mx = 1;
        int nr = nums.size();
        vector<int> inc(nr);
        vector<int> dec(nr);

        if (nums.empty())
            return 0;

        for (int i = 0; i < nr; ++i) {
            inc[i] = dec[i] = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] > nums[i]) {
                    dec[i] = max(dec[i], 1 + inc[j]);
                }
            }
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    inc[i] = max(inc[i], 1 + dec[j]);
                }
            }
            mx = max({mx, inc[i], dec[i]});
        }
        return mx;
    }
};

// v2
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int nr = nums.size();
        int mx = 1;
        vector<int> inc(nr);
        vector<int> dec(nr);

        if (nums.empty())
            return 0;

        inc[0] = 1;
        dec[0] = 1;
        for (int i = 1; i < nr; ++i) {
            if (nums[i] > nums[i-1]) {
                inc[i] = max(dec[i-1]+1, inc[i-1]);
                dec[i] = dec[i-1];
            } else if (nums[i] < nums[i-1]) {
                inc[i] = inc[i-1];
                dec[i] = max(inc[i-1]+1, dec[i-1]);
            } else {
                inc[i] = inc[i-1];
                dec[i] = dec[i-1];
            }
            mx = max({mx, inc[i], dec[i]});
        }
        return mx;
    }
};
