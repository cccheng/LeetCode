class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> que;
        vector<bool> visited(arr.size(), false);

        que.push(start);
        visited[start] = true;

        while (!que.empty()) {
            int cur = que.front();
            que.pop();

            if (arr[cur] == 0)
                return true;

            if (cur-arr[cur] >= 0 && !visited[cur-arr[cur]]) {
                que.push(cur - arr[cur]);
                visited[cur-arr[cur]] = true;
            }
            if (cur+arr[cur] < arr.size() && !visited[cur+arr[cur]]) {
                que.push(cur + arr[cur]);
                visited[cur+arr[cur]] = true;
            }
        }

        return false;
    }
};
