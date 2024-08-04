//M1
//Using simple maths and simulation
//Faster than 77.7% (3ms)

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" or num2 == "0")
            return "0";
        int n1 = num1.size(), n2 = num2.size();
        vector<int> res(n1 + n2, 0);

        for (int i = n2 - 1; i >= 0; i--) {
            for (int j = n1 - 1; j >= 0; j--) {
                int a = num2[i] - '0', b = num1[j] - '0';
                int temp = res[i + j + 1] + a * b;
                res[i + j + 1] = temp % 10;
                res[i + j] += temp / 10;
            }
        }

        string ans = "";
        int i = 0;
        while (i < res.size() and res[i] == 0)
            i++;

        for (; i < res.size(); i++)
            ans += res[i] + '0';

        return ans;
    }
};
