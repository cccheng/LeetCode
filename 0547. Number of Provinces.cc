class Solution {
public:
    map<int, int> dset;

    int dset_insert(int i) {
        dset[i] = i;
        return i;
    }

    int dset_find(int i) {
        if (dset.find(i) == dset.end())
            return -1;
        if (i != dset[i])
            dset[i] = dset_find(dset[i]);
        return dset[i];
    }

    void dset_union(int a, int b) {
        int set_a = dset_find(a);
        int set_b = dset_find(b);

        if (-1 == set_a) set_a = dset_insert(a);
        if (-1 == set_b) set_b = dset_insert(b);
        dset[set_b] = set_a;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        for (auto r = 0; r < isConnected.size(); ++r)
            for (auto c = 0; c < isConnected[r].size(); ++c)
                if (isConnected[r][c])
                    dset_union(r, c);

        vector<int> prov;
        for (auto& s : dset)
            prov.push_back(dset_find(s.first));

        sort(prov.begin(), prov.end());
        return distance(prov.begin(), unique(prov.begin(), prov.end()));
    }
};
