class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> result(A.size());

        sort(A.begin(), A.end());
        for (int i = 0 ; i < B.size(); ++i) {
            auto it = upper_bound(A.begin(), A.end(), B[i]);
            if (it != A.end()) {
                result[i] = *it;
                A.erase(it);
            } else {
                result[i] = A.front();
                A.erase(A.begin());
            }
        }

        return result;
    }
};
