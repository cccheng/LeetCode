class Solution {
public:
    int count(string& str, int offset) {
        int ret = 0;
        for (int i = 0; i < offset; i++) {
            if (str[i] == '1')
                ret += offset - i;
        }
        for (int i = offset + 1; i < str.size(); i++) {
            if (str[i] == '1')
                ret += i - offset;
        }
        return ret;
    }
    vector<int> minOperations(string boxes) {
        vector<int> result(boxes.size());
        
        for (int i = 0; i < boxes.size(); ++i)
            result[i] = count(boxes, i);
        
        return result;
    }
};
