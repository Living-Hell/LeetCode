//M1
//Using DP
//Faster than 100%(22ms)

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n,0), left(n,0), right(n,n);
        int ans = INT_MIN;

        for(int i=0; i<m; i++){
            int curr_left=0, curr_right=n;
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1') dp[j]++;
                else dp[j] = 0;
            }
            
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1') left[j] = max(curr_left, left[j]);
                else {
                    curr_left = j+1;
                    left[j] = 0;
                }
            }
            
            for(int j=n-1; j>=0; j--){
                if(matrix[i][j] == '1') right[j] = min(curr_right, right[j]);
                else {
                    curr_right = j;
                    right[j] = n;
                }
            }

            int temp=INT_MIN;
            for(int j=0; j<n; j++){
                temp = max(temp, dp[j] * (right[j] - left[j]));
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};