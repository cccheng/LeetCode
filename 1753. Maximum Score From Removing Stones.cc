class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> arr = {a, b, c};
        sort(arr.begin(), arr.end());
        
        if (arr[0] == 0 && arr[1] == 0)
            return 0;
        
        if (arr[0] == 0)
            return min(arr[1], arr[2]);
        
        int score = 0;
        if (arr[0] + arr[1] <= arr[2]) {
            return arr[0] + arr[1]; 
        } else {
            score = (arr[0] + arr[1] - arr[2]) / 2;    
            if (score != 0) {
                arr[0] -= score;
                arr[1] -= score;
            } else {
                arr[0] -= 1;
            }
        }
        
        return score + maximumScore(arr[0], arr[1], arr[2]);
    }
};
