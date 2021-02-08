
class Solution {
public:
    map<int, int> dset;

    int insert(int id) {
        dset[id] = id;
        return id;
    }

    int find(int id) {
        int n = id;

        if (dset.find(id) == dset.end())
            return -1;

        while (dset[n] != n)
            n = dset[n];
        dset[id] = n;

        return n;
    }

    void union_set(int a, int b) {
        dset[find(dset[b])] = find(a);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (auto e : edges) {
            int set_a = find(e[0]);
            int set_b = find(e[1]);

            if (-1 == set_a)
                set_a = insert(e[0]);
            if (-1 == set_b)
                set_b = insert(e[1]);

            if (set_a == set_b)
                return e;
            else
                union_set(e[0], e[1]);
        }
        return {};
    }
};
