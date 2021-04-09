class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> alpha;
        for (int i = 0 ; i < order.size(); ++i) {
            alpha[order[i]] = i;
        }

        auto less = [&alpha](const string& a, const string& b) -> bool {
            int i, j;
            for (i = 0, j = 0; i < a.size() && j < b.size(); ++i, ++j)
                if (alpha[a[i]] < alpha[b[j]])
                    return true;
                else if (alpha[a[i]] > alpha[b[j]])
                    return false;

            return a.size() <= b.size();
        };

        for (int i = 0; i < words.size() - 1; ++i) {
            if (!less(words[i], words[i+1]))
                return false;
        }
        return true;
    }
};
