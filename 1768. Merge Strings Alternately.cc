class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        result.resize(word1.size() + word2.size());
        
        int minlen = min(word1.size(), word2.size());
        for (int i = 0; i < minlen; i++ ) {
            result[2*i] = word1[i];
            result[2*i + 1] = word2[i];
        }
        if (word1.size() > minlen) {
            for (int i = minlen; i < word1.size(); i++)
                result[i + word2.size()] = word1[i];
        } else if (word2.size() > minlen) {
            for (int i = minlen; i < word2.size(); i++)
                result[i + word1.size()] = word2[i];       
        }
        
        return result;
    }
};
