#include<bits/stdc++.h>
using namespace std;

int solve(string &s, int index, char prev, int size, vector<vector<vector<int>>> &dp){
  	if(size==3)
        return 1;
    
    if(index>=(int)s.size())
        return 0;
  
    if(dp[index][prev-'A'][size]!=-1)
        return dp[index][prev-'A'][size];
        
    if(prev=='A' || prev!=s[index])
        return dp[index][prev-'A'][size]=solve(s,index+1,prev,size,dp)+solve(s,index+1,s[index],size+1,dp);
    
    
    return dp[index][prev-'A'][size]=solve(s,index+1,prev,size,dp);
}

int main(){
  string s1,s2;
    cin>>s1>>s2;
    
  	for(int i=0;i<(int)s1.size();i++)
      if(s1[i]!='L' && s1[i]!='M'){
        cout<<"Invalid Input"<<endl;
        return 0;
      }
  
  for(int i=0;i<(int)s2.size();i++)
      if(s2[i]!='L' && s2[i]!='M'){
        cout<<"Invalid Input"<<endl;
        return 0;
      }
  
    if(s1.size()<3 || s2.size()<3){
        cout<<"Invalid Input"<<endl;
        return 0;
    }
  	
  
    vector<vector<vector<int>>> dp1(s1.size()+1,vector<vector<int>>(26,vector<int>(4,-1)));
    int ans1=solve(s1,0,'A',0,dp1);
    vector<vector<vector<int>>> dp2(s2.size()+1,vector<vector<int>>(26,vector<int>(4,-1)));
    int ans2=solve(s2,0,'A',0,dp2);
    
    if(ans1>ans2)
        cout<<"Ashok"<<endl;
    else if(ans2>ans1)
        cout<<"Anand"<<endl;
    else
        cout<<"Draw"<<endl;
    return 0;
}