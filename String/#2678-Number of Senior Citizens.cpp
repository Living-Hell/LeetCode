//M1
//Simple Iteration
//Faster than 60.14% (6ms)

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(string &s:details){
            int age = (s[11]-'0')*10 + (s[12]-'0');
            res += age > 60;
        }
        return res;
    }
};
