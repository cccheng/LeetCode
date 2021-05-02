struct TrieNode {
    map<char,TrieNode*> children;
    int data;
};

struct Trie {
    TrieNode root;
    void insert(string s, int index) {
        TrieNode* cur = &root;
        cur->data = max(cur->data, index);

        for (int i = 0; i < s.size(); ++i) {
            if (!cur->children.count(s[i]))
                cur->children[s[i]] = new TrieNode();
            cur = cur->children[s[i]];
            cur->data = max(cur->data, index);
        }
    }

    int find(string s) {
        TrieNode* cur = &root;
        for (int i = 0; i < s.size(); ++i) {
            if (cur->children.count(s[i]))
                cur = cur->children[s[i]];
            else
                return -1;
        }
        return cur->data;
    }
};

class WordFilter {
    Trie prefix_tree;

public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            for (int j = words[i].size(); j >= 0; --j) {
                prefix_tree.insert(words[i].substr(j) + "#" + words[i], i);
            }
        }
    }

    int f(string prefix, string suffix) {
        return prefix_tree.find(suffix + "#" + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
