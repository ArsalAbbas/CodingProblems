    class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> in;
    unordered_map<string, pair<int, int>> out;
        
    void checkIn(int id, string stationName, int t) {
        in[id].first=stationName;
        in[id].second=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string route=in[id].first+"-"+stationName;
        out[route].first+= t- in[id].second;
        out[route].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        string route= startStation+"-"+endStation;
        return (double)out[route].first/out[route].second;
        
    }
};