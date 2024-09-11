//M1
//Using maths and bit manipulation
//Faster than 100% (0ms)

class Solution {
public:
    int minBitFlips(int start, int goal) {
        string num1 = "", num2 = "";
        if (goal > start)
            swap(goal, start);
        while (start > 0) {
            num1 += start % 2 ? "1" : "0";
            start /= 2;
        }

        while (goal > 0) {
            num2 += goal % 2 ? "1" : "0";
            goal /= 2;
        }
        int n1 = num1.size(), n2 = num2.size(), res = 0;

        for (int i = n2; i < n1; i++)
            num2 += "0";

        for (int i = 0; i < n1; i++)
            res += num1[i] != num2[i];

        return res;
    }
};

//
//
