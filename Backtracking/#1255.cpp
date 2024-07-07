//M1
//Using backtracking
//Faster than 31.08% (13ms)

class Solution {
public:
    int solve(vector<string>& words, vector<int> a, vector<int>& score, int ind){
        if(ind >= words.size()) 
            return 0;

        int res = 0;
        vector<int> b = a;
        bool check = 0;

        for(char c : words[ind]){
            res += score[c-'a'];
            b[c-'a']--;
            if(b[c-'a'] < 0) {
                check = 1;
                break;
            }
        }
        
        if(!check) 
            return max(res + solve(words,b,score,ind+1), solve(words, a, score, ind+1));
        return solve(words, a, score, ind+1);

    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> a(26,0);
        for(char c:letters) 
            a[c-'a']++;
        return solve(words,a,score,0);        
    }
};