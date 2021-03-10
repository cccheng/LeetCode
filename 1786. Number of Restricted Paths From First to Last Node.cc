class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> link(n+1);
        for (auto& e : edges) {
            link[e[0]].push_back({e[1], e[2]});
            link[e[1]].push_back({e[0], e[2]});
        }

        typedef pair<int,int> Node; // distance, node
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        vector<int> distance(n+1, numeric_limits<int>::max());
        distance[n] = 0;
        pq.push({0, n});

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            for (auto [i, w] : link[node]) {
                if (distance[i] > dist + w) {
                    distance[i] = dist + w;
                    pq.push({dist + w, i});
                }
            }
        }

        vector<int> nr_path(n+1, -1);
        nr_path[n] = 1;

        function<int(int)> dfs = [&](int node) -> int {
            if (nr_path[node] == -1) {
                nr_path[node] = 0;
                for (auto [i, w] : link[node]) {
                    if (distance[i] < distance[node]) {
                        nr_path[node] += dfs(i);
                        nr_path[node] %= 1000000007;
                    }
                }
            }

            return nr_path[node];
        };

        dfs(1);

        return nr_path[1];
    }
};
