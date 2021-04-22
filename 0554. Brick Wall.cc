class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int nr_row = wall.size();
        vector<int> idx(nr_row);
        vector<int> pos(nr_row);

        typedef pair<int,int> ii; // pos, row
        priority_queue<ii, vector<ii>, greater<ii>> pq;

        for (int r = 0; r < nr_row; ++r) {
            idx[r] = 0;
            pos[r] = wall[r][0];
            pq.push({pos[r], r});
        }

        int cur_pos = 0;
        int mn = nr_row;

        while (!pq.empty()) {
            int row;
            tie(cur_pos, row) = pq.top();
            pq.pop();

            pos[row] = cur_pos;
            idx[row]++;

            if (idx[row] < wall[row].size()) {
                pq.push({cur_pos + wall[row][idx[row]], row});
            } else {
                break;
            }

            while (!pq.empty() && pq.top().first == cur_pos) {
                row = pq.top().second;
                pq.pop();

                pos[row] = cur_pos;
                idx[row]++;

                if (idx[row] < wall[row].size()) {
                    pq.push({cur_pos + wall[row][idx[row]], row});
                }
            }

            int count = 0;
            for (int r = 0; r < nr_row; ++r) {
                if (pos[r] != cur_pos)
                    count++;
            }
            mn = min(mn, count);
        }

        return mn;
    }
};
