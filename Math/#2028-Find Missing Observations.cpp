//M1
//Using maths and simple intuition
//Faster than 67.65% (97ms)

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> res;
        int tsum = 0, m = rolls.size();
        for (int i = 0; i < m; i++) {
            tsum += rolls[i];
        }
        int total = mean * (m + n);
        int req = total - tsum;
        if (req > 6 * n or req < n)
            return res;
        int val = req / n, high = req % n;
        n -= high;
        while (high--)
            res.push_back(val + 1);
        while (n--)
            res.push_back(val);
        return res;
    }
};
