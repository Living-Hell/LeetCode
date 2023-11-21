// M1
// Using if else
// Faster than 100% (0 ms)

class Solution
{
public:
    string intToRoman(int num)
    {
        string ans = "";

        int m = num / 1000;
        num = num % 1000;
        while (m--)
            ans += "M";

        int cm = num / 900;
        num = num % 900;
        while (cm--)
            ans += "CM";

        int d = num / 500;
        num = num % 500;
        while (d--)
            ans += "D";

        int cd = num / 400;
        num = num % 400;
        while (cd--)
            ans += "CD";

        int c = num / 100;
        num = num % 100;
        while (c--)
            ans += "C";

        int xc = num / 90;
        num = num % 90;
        while (xc--)
            ans += "XC";

        int l = num / 50;
        num = num % 50;
        while (l--)
            ans += "L";

        int xl = num / 40;
        num = num % 40;
        while (xl--)
            ans += "XL";

        int x = num / 10;
        num = num % 10;
        while (x--)
            ans += "X";

        int ix = num / 9;
        num = num % 9;
        while (ix--)
            ans += "IX";

        int v = num / 5;
        num = num % 5;
        while (v--)
            ans += "V";

        int iv = num / 4;
        num = num % 4;
        while (iv--)
            ans += "IV";

        int i = num / 1;
        num = num % 1;
        while (i--)
            ans += "I";

        return ans;
    }
};