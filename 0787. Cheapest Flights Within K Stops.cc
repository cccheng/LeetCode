class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> edge(n+1, vector<int>(n+1, -1));
        for (auto& f : flights)
            edge[f[0]][f[1]] = f[2];

        typedef tuple<int,int,int> Node; // stop, node, current price
        auto cmp = [](auto& a, auto& b) -> bool {
                return get<2>(a) > get<2>(b);
            }; // min heap
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

        for (int i = 0; i <= n; ++i)
            if (edge[src][i] != -1)
                pq.push({0, i, edge[src][i]});

        while (!pq.empty()) {
            auto [stop, node, cur_price] = pq.top();
            pq.pop();

            if (stop > K)
                continue;

            if (node == dst)
                return cur_price;

            for (int i = 0; i <= n; ++i) {
                if (edge[node][i] != -1)
                    pq.push({stop+1, i, cur_price + edge[node][i]});
            }
        }

        return -1;
    }
};
