class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank, cur;;
        int nr = gas.size();
        for (int i = 0, s = 0; i < nr; ++i) {
            tank = 0;
            for (s = 0; s < nr; s++) {
                cur = (i + s) % nr;
                tank += gas[cur];
                tank -= cost[cur];
                if (tank < 0)
                    break;
            }

            if (s == nr)
                return i;
	    i += s + 1;
        }

        return -1;
    }
};
