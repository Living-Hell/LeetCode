//M1
//Using iteration and simulation
//Faster than 100% (0 ms)

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int res = 0, n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += satisfaction[j] * (j-i+1);
            }
            res = max(sum,res);
        }
        return res;
    }
};