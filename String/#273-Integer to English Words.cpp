//M1
//Using Simulation and recursion
//Faster than 100% (0ms)

class Solution {
public:
    vector<string> suff = {"Billion ", "Million ", "Thousand "};
    vector<string> dig = {"",         "One ",       "Two ",      "Three ",
                          "Four ",    "Five ",      "Six ",      "Seven ",
                          "Eight ",   "Nine ",      "Ten ",      "Eleven ",
                          "Twelve ",  "Thirteen ",  "Fourteen ", "Fifteen ",
                          "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    vector<string> tens = {"Twenty ", "Thirty ",  "Forty ",  "Fifty ",
                           "Sixty ",  "Seventy ", "Eighty ", "Ninety "};

    string solve(int num) {
        if (num == 0)
            return "";
        string res = "";
        if (num >= 100) {
            res += dig[num / 100] + "Hundred ";
            num = num % 100;
        }
        if (num >= 20) {
            res += tens[num / 10 - 2];
            num = num % 10;
            res += dig[num];
        } else {
            res += dig[num];
        }
        return res;
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string res = "";
        for (int i = 3; i > 0; i--) {
            int n = num / pow(10, i * 3);
            if (n > 0) {
                res += solve(n) + suff[3 - i];
                num = num % ((int)pow(10, i * 3));
            }
        }
        res += solve(num);
        res.pop_back();
        return res;
    }
};
