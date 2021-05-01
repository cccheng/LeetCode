class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> result;
        
        auto _pow = [](int a, int b) -> int {
            int r = 1;
            for (int i = 0; i < b; ++i) {
                r *= a;
            }
            return r;
        };
        
        for (int i = 0; _pow(x,i) <= bound; i++) {
            for (int j = 0; _pow(x,i) + _pow(y,j) <= bound; j++) {
                result.push_back(_pow(x,i) + _pow(y,j));
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
