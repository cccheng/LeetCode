class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        vector<int> count(A.size());

        if (A.size() < 3)
            return 0;
        
        for (int i = 2; i < A.size(); ++i ) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2])
                count[i] = count[i - 1] + 1;
            result += count[i];
        }
        
        return result;
    }
};
