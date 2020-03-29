class UndergroundSystem {
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        auto& item = beginStatus[id];
        item.first = stationName;
        item.second = t;
    }

    void checkOut(int id, string stationName, int t) {
        const auto& item = beginStatus[id];
        const auto& startStation = item.first;
        auto& value = status[startStation][stationName];
        value.first += (t-item.second);
        value.second += 1;
    }

    double getAverageTime(string startStation, string endStation) {
        const auto& item = status[startStation][endStation];
        return (double)item.first / item.second;
    }
private:
    std::map<std::string, std::map<std::string, std::pair<int, int>>> status;
    std::map<int, std::pair<std::string, int>> beginStatus;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */