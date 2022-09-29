//M1
//Using Recursion and Backtracking
//Faster Than 34.31% (10 ms)

class Solution {
public:
    void Parenthesis( vector<string> &ans, int n, int open, int close, string str){
        
        if(open > n) return;
        
        if(open == n && close == n){
            ans.push_back(str);
            return;
        }
        
        if(open>close)
            Parenthesis(ans,n,open,close+1,str+")");
        
        Parenthesis(ans,n,open+1,close,str+"(");
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        Parenthesis(ans,n,0,0,"");
        return ans;
        
    }
};