// M1
// Using bit logic
// Faster than 100% (0ms)

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int m = a.size() - 1, n = b.size() - 1;
        int carry = 0;

        if (m < n)
            swap(a, b);
        for (int i = b.size(); i < a.size(); i++)
            b = "0" + b;

        m = n = max(m, n);

        while (m >= 0)
        {
            if (a[m] == '1' and b[n] == '1')
            {
                if (carry == 0)
                {
                    a[m] = '0';
                    carry = 1;
                }
            }
            else if (a[m] == '1' and b[n] == '0')
            {
                if (carry == 1)
                {
                    a[m] = '0';
                }
            }
            else if (a[m] == '0' and b[n] == '1')
            {
                if (carry == 1)
                {
                    a[m] = '0';
                }
                else
                {
                    a[m] = '1';
                }
            }
            else
            {
                if (carry)
                {
                    a[m] = '1';
                    carry = 0;
                }
            }
            m--, n--;
        }
        if (carry)
            a = "1" + a;
        return a;
    }
};
