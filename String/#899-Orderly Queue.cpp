//M1
//Using sorting and intuition
//Faster than 44.89% (4ms)

class Solution {
public:
    string orderlyQueue(string s, int k) {
        string temp = s;
        sort(temp.begin(), temp.end());
        if (k > 1)
            return temp;

        int n = s.size();
        string res = s;
        for (int i = 1; i < n; i++) {
            string ans = s.substr(i) + s.substr(0, i);
            res = min(ans, res);
        }
        return res;
    }
};
