class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        map<char,int> mapping = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000} 
        };
        
        for (int i = 0; i < s.size(); ++i) {
            char cur = s[i], next = '_';
            if (i + 1 < s.size())
                next = s[i + 1];
            
            if (cur == 'I' && next =='V') {
                result += 4; i++;
            } else if (cur == 'I' && next =='X') {
                result += 9; i++;
            } else if (cur == 'X' && next =='L') {
                result += 40; i++;
            } else if (cur == 'X' && next =='C') {
                result += 90; i++;
            } else if (cur == 'C' && next =='D') {
                result += 400; i++;
            } else if (cur == 'C' && next =='M') {
                result += 900; i++;
            } else {
                result += mapping[cur];
            }
        }
        
        return result;
    }
};
