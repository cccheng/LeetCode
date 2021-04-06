class Solution {
public:
    int minOperations(int n) {
        int width = n/2;
        return ((n-1)+(n%2?2:1))*width/2;
    }
};
