//M1
//Using Kadane's Algorithm
//Faster than 71.44% (135ms)

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();    
        long long int ans = arr[0], curr_sum=0;
        
        for(int i=0; i<n; i++){
            curr_sum += arr[i];
            ans = max(ans,curr_sum);
            if(curr_sum<0) curr_sum=0;
        }
        return ans;
    }
};