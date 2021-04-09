class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for (auto c : s)
            freq[c]++;

        sort(s.begin(), s.end(), [&freq](auto a, auto b)
             { return freq[a] > freq[b] || (freq[a] == freq[b] && a > b); });
        return s;
    }
};
