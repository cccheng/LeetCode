class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> edge(n+1, vector<int>(n+1, -1));
        for (auto t : times) edge[t[0]][t[1]] = t[2];

        vector<int> distance(n+1, -1);

        typedef pair<int,int> Node; // node, length
        auto cmp = [](Node& a, Node& b) { return a.second > b.second; }; // for min heap
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

        pq.push({k, 0});

        while (!pq.empty()) {
            int node = pq.top().first;
            int cur_len = pq.top().second;
            pq.pop();

            if (distance[node] != -1 && distance[node] < cur_len)
                continue;
            distance[node] = cur_len;

            for (int i = 1; i <= n; ++i) {
                if (edge[node][i] == -1)
                    continue;
                if (distance[i] != -1)
                    continue;

                pq.push({i, cur_len + edge[node][i]});
            }
        }

        int mx = -1;
        for (int i = 1; i <= n; ++i) {
            if (distance[i] == -1)
                return -1;
            mx = max(mx, distance[i]);
        }
        return mx;
    }
};
