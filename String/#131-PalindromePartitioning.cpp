//M1
//Using backtracking
//Faster than 53.53%(204ms)

class Solution {
public:
    bool isPalindrome(string s){
        int n = s.size();
        for(int i=0; i<(n+1)/2; i++)
            if(s[i] != s[n-i-1])
                return false;
        return true;
    }

    void helper(string s, vector<string> curr, vector<vector<string>> &ans){
        if(s.empty()) return;
        if(isPalindrome(s)){
            curr.push_back(s);
            ans.push_back(curr);
            curr.pop_back();
        }
        if(s.size()==1){
            return;
        }
        for(int i=0; i<s.size(); i++){
            string sub = s.substr(0,i+1);
            if(isPalindrome(sub)){
                curr.push_back(sub);
                helper(s.substr(i+1),curr, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> curr;
        helper(s, curr, ans);
        return ans;
    }
};