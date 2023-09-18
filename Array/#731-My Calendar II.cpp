// M1
// Using array and simulation
// Faster than 96.11% (73ms)

class MyCalendarTwo
{
public:
    vector<pair<int, int>> booking, dbooking;
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        for (auto const &d : dbooking)
        {
            if (start < d.second and end > d.first)
                return false;
        }
        for (auto const &p : booking)
        {
            if (start < p.second and end > p.first)
                dbooking.push_back({max(start, p.first), min(end, p.second)});
        }
        booking.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */