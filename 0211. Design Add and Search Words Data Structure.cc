struct TrieNode {
    map<char,TrieNode*> next;
    bool end;
    TrieNode() {
        end = false;
    }
};

class WordDictionary {
    TrieNode root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    void addWord(string word) {
        TrieNode* node = &root;
        for (auto c : word) {
            if (!node->next.count(c))
                node->next[c] = new TrieNode;
            node = node->next[c];
        }
        node->end = true;
    }

    bool search(string word) {
        bool found = false;

        function<void(int,TrieNode*)> dfs = [&](int offset, TrieNode* node) {
            if (!node)
                return;

            if (offset == word.size()) {
                if (node->end) found = true;
                return;
            }

            char target = word[offset];
            if (target != '.' && !node->next.count(target))
                return;

            if (target != '.') {
                dfs(offset + 1, node->next[target]);
            } else {
                for (auto n : node->next)
                    dfs(offset + 1, n.second);
            }
        };

        dfs(0, &root);
        return found;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
