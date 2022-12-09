//M1
//Using DP
//Faster than 90.27% (10ms)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){

                if(i==0 and j==0) continue;
                
                int up = INT_MAX;
                if(i>0) up = grid[i-1][j];
                
                int left = INT_MAX;
                if(j>0) left = grid[i][j-1];

                grid[i][j] += min(up,left);
            }
        }

        return grid[n-1][m-1];
    }
};