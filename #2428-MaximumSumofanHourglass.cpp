//M1
//Iteration
//Faster than 83.78% (46ms)

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int ans=0, sum=0;
        
        for(int i=0; i<m-2; i++){
            for(int j=0; j<n-2; j++){
                for(int k=0; k<3; k++){
                    sum+= grid[i][j+k] + grid[i+2][j+k];
                }                
                sum+= grid[i+1][j+1];
                ans = max(ans,sum);
                sum=0;
            }
        }
        
        return ans;
        
    }
};