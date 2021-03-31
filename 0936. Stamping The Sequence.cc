class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        bool placed;
        vector<int> result;

        auto match = [&](int index) -> bool {
            bool matched = false;
            for (int j = 0; j < stamp.size(); ++j) {
                if (target[index+j] == '?')
                    continue;
                if (target[index+j] == stamp[j]) {
                    matched = true;
                    continue;
                }
                return false;
            }
            return matched;
        };

        do {
            placed = false;
            for (int i = 0; i < target.size() - stamp.size() + 1; ++i) {
                if (match(i)) {
                    placed = true;
                    result.push_back(i);
                    for (int j = 0; j < stamp.size(); ++j) {
                        target[i+j] = '?';
                    }
                }
            }
        } while(placed);

        for (int i = 0; i < target.size(); ++i) {
            if (target[i] != '?')
                return {};
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
