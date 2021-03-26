class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> result;
        
        multiset<char> bset;
        for (auto& b : B) {
            multiset<char> tmp;
            multiset<char> _b(b.begin(), b.end());
            set_union(bset.begin(), bset.end(), _b.begin(), _b.end(), inserter(tmp, tmp.end()));
            bset.swap(tmp);
        }
        
        for (auto& a : A) {
            multiset<char> aset(a.begin(), a.end());
            if (std::includes(aset.begin(), aset.end(), bset.begin(), bset.end()))
                result.emplace_back(a);
        }
        
        return result;
    }
};
