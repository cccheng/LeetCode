class TrieNode {
public:
    map<char,TrieNode*> next;
    bool isLeaf;
    TrieNode() : isLeaf(false) {}
};

class Trie {
    TrieNode root;

public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = &root;
        for (auto c : word) {
            if (!cur->next.count(c))
                cur->next[c] = new TrieNode();
            cur = cur->next[c];
        }
        cur->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = &root;
        for (auto c : word) {
            if (!cur->next.count(c))
                return false;
            cur = cur->next[c];
        }
        return cur->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = &root;
        for (auto c : prefix) {
            if (!cur->next.count(c))
                return false;
            cur = cur->next[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
