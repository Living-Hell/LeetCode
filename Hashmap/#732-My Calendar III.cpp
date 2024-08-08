//M1
//Using Line Sweep Algorithm
//Faster than 70.06% (76ms)

class MyCalendarThree {
public:
    map<int,int> mp;
    MyCalendarThree() {
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int cnt = 0, res = 0;
        for(auto &[i,j] : mp){
            cnt += j;
            res = max(res,cnt);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
