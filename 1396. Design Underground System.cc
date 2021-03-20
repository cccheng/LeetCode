class UndergroundSystem {
    map<pair<string,string>,vector<int>> records;
    map<int,pair<string,int>> ongoing;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ongoing[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = ongoing.find(id);
        records[{it->second.first, stationName}].emplace_back(t - it->second.second);        
        ongoing.erase(it);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto ti = records[{startStation, endStation}];
        double sum = accumulate(ti.begin(), ti.end(), 0);
        return sum / ti.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
