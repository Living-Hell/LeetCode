//Using simulation
//Faster than 78.56% (26ms)

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0, n = timeSeries.size();
        if(n==1) return duration;

        for(int i=1; i<n; i++){
            res += min(timeSeries[i] - timeSeries[i-1], duration);
        }
        res += duration;
        return res;
    }
};