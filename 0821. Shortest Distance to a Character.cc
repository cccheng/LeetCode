class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size());
        
        int begin = -1;
        int end = s.find_first_of(c);
        for( auto i = 0; i < end; ++i)
            ans[i] = end - i;
        
        begin = end;
        end = s.find_first_of(c, begin + 1);
        while (end != string::npos) {
            ans[begin] = 0;
            for (auto i = begin + 1; i < end; ++i) {
                ans[i] = min(i - begin, end - i);
            }
            begin = end;
            end = s.find_first_of(c, end + 1);
        }
        
        for (auto i = begin + 1; i < ans.size(); ++i)
            ans[i] = i - begin;
        
        return ans;
    }
};
