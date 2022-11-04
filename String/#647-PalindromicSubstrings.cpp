//M1
//Solved using DP
//Faster Than 56.25% (18ms)

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        bool dp[n][n];

        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n; i++,j++){
                if(g==0)
                    dp[i][j] = true;

                else if(g==1){
                    if(s[i] == s[j])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
    
                else{
                    if(s[i] == s[j] && dp[i+1][j-1] == true)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }

                if(dp[i][j])
                    count++;

            }
        }

        return count;
    }
};

//M2
//Solved by expansion around the center approach
//Faster Than 94% (3ms)

class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size(), count=0;
        vector<int> a(n,-1);
        
        for(int i=0; i<n; i++){
            int front=i, back=i;
            
            while(front<n && back>=0){
                if(s[front] == s[back])
                    count++;
                else
                    break;                
                front++;
                back--;
            }
            
            front= i+1; back=i;
            
            while(front<n && back>=0){
                if(s[front] == s[back])
                    count++;
                else
                    break;                
                front++;
                back--;
            }
        }
        
        return count; 
        
    }
};