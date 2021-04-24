class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        map<int, set<int>> graph;
        vector<int> rank(n, -1);

        for (auto& c : connections) {
            graph[c[0]].insert(c[1]);
            graph[c[1]].insert(c[0]);
        }

        function<int(int,int,int)> dfs = [&](int node, int parent, int r) -> int {
            if (rank[node] != -1)
                return rank[node];

            int ret = r;
            rank[node] = r;

            vector<int> remove;
            for (auto nei : graph[node]) {
                if (nei == parent)
                    continue;
                int _rk = dfs(nei, node, r+1);
                if (_rk <= r) {
                    ret = min(ret, _rk);
                    remove.push_back(nei);
                }
            }
            for (auto nei : remove) {
                graph[node].erase(nei);
                graph[nei].erase(node);
            }

            rank[node] = -1;
            return ret;
        };

        //for (int i = 0; i < n; ++i) {
        //    dfs(i, -1, 0);
        //}
        dfs(0, -1, 0);

        vector<vector<int>> result;
        for (auto& node : graph) {
            for (auto nei : node.second) {
                if (node.first < nei)
                    result.push_back({node.first, nei});
            }
        }
        return result;
    }
};
