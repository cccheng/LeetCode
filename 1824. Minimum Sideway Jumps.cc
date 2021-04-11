class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<int> lan(4, 0);
        vector<int> tmp(4, 0);
        
        lan[1] = lan[3] = numeric_limits<int>::max()/2;
        
        for (int i = 0; i < obstacles.size(); ++i) {
            for (int l = 1; l <= 3; ++l)
                tmp[l] = (obstacles[i] == l) ? numeric_limits<int>::max()/2 : lan[l];

            lan[1] = (obstacles[i] == 1) ? tmp[1] : min({tmp[1], tmp[2]+1, tmp[3]+1});
            lan[2] = (obstacles[i] == 2) ? tmp[2] : min({tmp[1]+1, tmp[2], tmp[3]+1});
            lan[3] = (obstacles[i] == 3) ? tmp[3] : min({tmp[1]+1, tmp[2]+1, tmp[3]});
        }
        
        return min({lan[1], lan[2], lan[3]});
    }
};
