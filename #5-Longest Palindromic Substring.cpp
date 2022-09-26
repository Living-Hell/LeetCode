//M1
//Solved by expansion around the center approach
//Faster Than 78.5% (24ms)

class Solution {
public:    
    string longestPalindrome(string s) {
        
        int n = s.size();
        
        if(n==1) return s;
        
        int start = 0, anslen = 0;
        
        for(int i=0; i<n; i++){
            int front=i, back=i;
            
            while(front<n && back>=0 && s[front] == s[back]){
                front++;
                back--;
            }
            
            int len1 = front - back -1;
            
            front= i+1; back=i;
            
            while(front<n && back>=0 && s[front] == s[back]){
                front++;
                back--;
            }
            
            int len2 = front - back -1;
            
            int len = max(len1,len2);
            
            if(len>anslen){
                anslen = len;
                start = i - (len-1)/2;
            }
        }
        
        string ans = s.substr(start, anslen);
        
        return ans;
        
    }
};

//M1
//Naive Aproach
//Faster Than 29.69% (371ms)

class Solution {
public:    
    string longestPalindrome(string s) {
        
        if(s.size() == 1) return s;
        
        int n = s.size();
        string ans = s.substr(0,1);
        
        for(int i=0; i<n-1; i++){
            int pos = i+1;
            
            while(pos<n){
                
                if(s[pos] == s[i] && pos-i+1 >= ans.size()){
                    
                    bool flag=1;
                    
                    for(int k=0; k<(pos-i+1)/2; k++){
                        if(s[i+k] != s[pos-k])
                            flag=0;
                    }
                    
                    if(flag && (pos-i+1) >= ans.length()){
                        ans = s.substr(i, pos-i+1);
                    }
                    
                }
                
                pos++;
                
            }
            
        }
        
        return ans;
        
    }
};