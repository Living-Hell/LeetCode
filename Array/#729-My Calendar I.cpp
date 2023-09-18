// M1
// Using array and simulation
// Faster than 50.9% (95ms)

class MyCalendar
{
public:
    vector<pair<int, int>> booking;
    MyCalendar()
    {
        booking = {};
    }

    bool book(int start, int end)
    {
        if (booking.size() == 0)
        {
            booking.push_back({start, end - 1});
            return true;
        }
        else
        {
            for (auto const &p : booking)
            {
                if ((start >= p.first and start <= p.second) or
                    (end - 1 >= p.first and end - 1 <= p.second) or (start < p.first and end - 1 > p.second))
                    return false;
            }
            booking.push_back({start, end - 1});
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */