class UndergroundSystem {
    map<pair<string,string>,pair<int,int>> records;
    unordered_map<int,pair<string,int>> ongoing;
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        ongoing[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto it = ongoing.find(id);
        auto& r = records[{it->second.first, stationName}];
        r.first += t - it->second.second;
        r.second += 1;
        ongoing.erase(it);
    }

    double getAverageTime(string startStation, string endStation) {
        auto& ti = records[{startStation, endStation}];
        return ((double)ti.first)/ti.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
