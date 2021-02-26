class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int degree = -1, min_diff = 0, target = -1, diff;
        int count, min, max;
        map<int, tuple<int,int,int>> freq; // count,min,max
        
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if (freq.count(n)) {
                tie(count,min,max) = freq[n];
                freq[n] = {++count,min,i};
                diff = i - min + 1;
            } else {
                count = 1;
                freq[n] = {count,i,i};
                diff = 1;
            }
            if (count > degree) {
                degree = count;
                min_diff = diff;
                target = n;
            } else if (count == degree && diff < min_diff) {
                min_diff = diff;
                target = n;
            }
        }
        
        return min_diff;
    }
};
