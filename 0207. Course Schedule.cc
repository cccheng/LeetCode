class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> graph;
        vector<int> indegree(numCourses);

        for (auto v : prerequisites) {
            graph[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        queue<int> source;
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0)
                source.push(i);
        }

        while (!source.empty()) {
            int node = source.front();
            source.pop();
            for (auto to : graph[node]) {
                if (indegree[to] != 0)
                    indegree[to]--;
                if (indegree[to] == 0)
                    source.push(to);
            }
        }

        return indegree.end() == find_if(indegree.begin(), indegree.end(), [](auto i) { return i != 0;});
    }
};
