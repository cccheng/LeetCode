class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        
        for (int l = 0; l < s.size(); ++l) {
            map<char,int> count;
            unordered_set<string> used; 
            
            count[s[l]]++;
            int mx = count[s[l]];
            int mn = numeric_limits<int>::max();
            for (int r = l+1; r < s.size(); ++r) {
                bool old = count.count(s[r]) ? true : false;
                
                count[s[r]]++;
                mx = max(mx, count[s[r]]);
                
                if (!old) mn = 1;
                else {
                    mn = count[s[r]];
                    for (auto p : count) mn = min(mn, p.second);
                }
                
                if (mn != numeric_limits<int>::max())
                    sum += (mx - mn);
            }
        }
        
        return sum;
    }
};
