class Solution {
public:
    map<char,char> dset;

    char dset_insert(char c) {
        dset[c] = c;
        return c;
    }
    char dset_find(char c) {
        if (dset.find(c) == dset.end())
            return dset_insert(c);
        if (dset[c] != c)
            dset[c] = dset_find(dset[c]);
        return dset[c];
    }
    void dset_union(char a, char b) {
        dset[dset_find(b)] = dset_find(a);
    }
    bool equationsPossible(vector<string>& equations) {
        for (auto str : equations) {
            if (str[1] == '=') {
                char root_a = dset_find(str[0]);
                char root_b = dset_find(str[3]);
                if (root_a != root_b)
                    dset_union(str[0], str[3]);
            }
        }
        for (auto str : equations) {
            char root_a = dset_find(str[0]);
            char root_b = dset_find(str[3]);
            if (str[1] == '!') {
                if (root_a == root_b)
                    return false;
            }
        }
        return true;
    }
};
