class Solution {

    bool solve(const vector<int>& vec, int h, int k) {
        for (int i = vec.size()-1; i >= 0; --i) {
            h -= (vec[i] +k-1) / k;
            if (h < 0)
                return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int l = 1, r = piles.back()+1, m;
        while (l < r) {
            m = l + (r-l) / 2;

            if (solve(piles, h, m))
                r = m;
            else
                l = m+1;
        }

        return l;
    }
};
