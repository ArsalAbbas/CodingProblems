class MyCalendar
{
public:
    set<pair<int, int>> tt;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        auto x = tt.lower_bound({end,0});
        if (x == tt.begin() || (--x)->second <= start)
            return tt.insert({start, end}).second;
        return false;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */