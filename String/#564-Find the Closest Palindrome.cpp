//M1
//Using simulation and brute force
//Faster than 34.22% (4ms)

class Solution {
public:
    string nearestPalindromic(string num) {
        int n = num.size();
        if (n == 1)
            return to_string(stol(num) - 1);
        string number = num;
        long long int n1 = pow(10, n) + 1;
        long long int n2 = pow(10, n - 1) - 1;

        string num1 = to_string(n1), num2 = to_string(n2);
        long long diff1 = abs(stol(num1) - stol(num));
        long long diff2 = abs(stol(num2) - stol(num));
        long long diff = min(diff1, diff2);

        string res = diff1 > diff2 ? num2 : num1;

        vector<int> incr = {0, 1, -1};
        string newNum;

        for (int add : incr) {
            int half = (n + 1) / 2;
            string temp = num.substr(0, half);
            long long int first = stol(temp);
            string firstHalf = to_string(first + add);
            string secondHalf = firstHalf;
            if (n % 2 == 1)
                secondHalf.pop_back();
            reverse(secondHalf.begin(), secondHalf.end());
            newNum = firstHalf + secondHalf;
            int tdiff = abs(stol(number) - stol(newNum));
            if (newNum != number and tdiff <= diff) {
                if (tdiff == diff) {
                    res = stol(res) < stol(newNum) ? res : newNum;
                    continue;
                }
                diff = tdiff;
                res = newNum;
            }
        }
        return res;
    }
};
