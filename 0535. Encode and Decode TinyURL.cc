class Solution {
private:
    unordered_map<string,string> s_to_l;
    unordered_map<string,string> l_to_s;
    string last = "abcdefghijk";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (l_to_s.count(longUrl))
            return l_to_s[longUrl];

        string shortUrl = last;
        next_permutation(last.begin(), last.end());

        l_to_s[longUrl] = shortUrl;
        s_to_l[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (!s_to_l.count(shortUrl))
            return "";
        return s_to_l[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
