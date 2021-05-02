class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });
        
        int cur = 0;
        multiset<int> taken;
        for (int i = 0; i < courses.size(); ++i) {
            if (cur + courses[i][0] <= courses[i][1]) {
                cur += courses[i][0];
                taken.insert(courses[i][0]);
            } else if (!taken.empty()) {
                if (*taken.rbegin() < courses[i][0])
                    continue;
                cur -= *taken.rbegin();
                taken.erase(--taken.end());
                cur += courses[i][0];
                taken.insert(courses[i][0]);
            }
        }
        
        return taken.size();
    }
};
