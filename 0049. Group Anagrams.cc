class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mapping;

        for (auto& s: strs) {
            string sorted(s);
            sort(sorted.begin(), sorted.end());

            auto i = mapping.find(sorted);
            if (i != mapping.end())
                i->second.push_back(s);
            else
                mapping[sorted] = vector<string>({s});
        }

        vector<vector<string>> result;
        for (auto& m : mapping)
            result.push_back(m.second);

        return result;
    }
};
