class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<bool> merged(words.size());
        sort(words.begin(), words.end(), [](auto& a, auto& b) -> bool { return a.size() > b.size(); });

        for (int i = 0; i < words.size(); ++i) {
            for (int j = i+1; j < words.size(); ++j)
                if (!merged[j] && words[i].find(words[j], words[i].size() - words[j].size()) != string::npos)
                    merged[j] = true;
        }

        int result = 0;
        for (int i = 0; i < merged.size(); ++i)
            if (!merged[i])
                result += words[i].size() + 1;

        return result;
    }
};
