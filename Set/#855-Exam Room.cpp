// M1
// Using ordered sets
// Faster than 21.27% (609ms)

class ExamRoom
{
public:
    set<int> seats;
    int tseats;
    ExamRoom(int n)
    {
        tseats = n;
    }

    int seat()
    {
        if (seats.size() == 0)
        {
            seats.insert(0);
            return 0;
        }

        auto it = seats.begin();
        int ans = *it, seat = 0;
        if (ans == 0)
            it++;

        while (it != seats.end())
        {
            if (ans < (*it - *prev(it)) / 2)
            {
                ans = (*it - *prev(it)) / 2;
                seat = (*it + *prev(it)) / 2;
            }
            it++;
        }

        if (ans < (tseats - 1) - *(seats.rbegin()))
        {
            ans = (tseats - 1) - *(seats.rbegin());
            seat = tseats - 1;
        }

        seats.insert(seat);
        return seat;
    }

    void leave(int p)
    {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */