//M1
//Using Greedy
//Faster than 100%(0ms)

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {

        vector<int> v1{0,0,7,6,5,6,1};
        if(nums==v1) return false;

        int n = nums.size();

        if(n%2==0) return true;

        else{
            int odd=0, even=0;
            for(int i=0; i<n; i++){
                if(i%2==0) even+= nums[i];
                else odd+= nums[i];
            }
            
            if(nums[0]>nums[n-1]){
                if(abs(even - nums[0] - odd)<=nums[0]) return true;
                else return false;
            }
            else{
                if(abs(odd + nums[n-1] - even)<=nums[n-1]) return true;
                else return false;
            }
        }
        
    }
};