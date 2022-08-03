class MyCalendar {
 vector<pair<int , int>>vec;
    
    public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        for(auto i : vec){
            //comdition for double booking.
            if(i.first < end && i.second > start ){
                return false;
            }
        }
        //if no double booking case then push the
        //element in vector.
        vec.push_back({start , end});
        //return true.
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */