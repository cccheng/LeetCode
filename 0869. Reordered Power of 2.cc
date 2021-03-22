class Solution {
    vector<string> powerof2;
public:
    Solution() {
        for (int n = 0; pow(2,n) <= 1000000000; n++) {
            string str = to_string((int)pow(2, n));
            sort(str.begin(), str.end());
            powerof2.push_back(str);
        }        
    }
    bool reorderedPowerOf2(int N) {
        string target = to_string(N);
        sort(target.begin(), target.end());
        return find(powerof2.begin(), powerof2.end(), target) != powerof2.end();
    }
};
