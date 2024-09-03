//M1
//Using simulation and intuition
//Faster than 25.74% (5ms)

class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0, n = s.size();
        string num = "";
        for (int i = 0; i < n; i++) {
            num += to_string(s[i] - 'a' + 1);
        }
        if (num.size() == 1)
            return stoi(num);
        while (k-- && num.size() > 1) {
            int temp = 0;
            for (char& c : num) {
                temp += c - '0';
            }
            res = temp;
            num = to_string(temp);
        }
        return res;
    }
};
