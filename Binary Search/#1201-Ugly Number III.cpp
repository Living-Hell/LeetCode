// M1
// Using Binary search and maths
// Faster than 52.1% (2ms)

class Solution
{
public:
    long long int gcd(long long int a, long long int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    long long int lcm(long long int a, long long int b)
    {
        return (a * b / gcd(a, b));
    }
    int nthUglyNumber(int n, int a, int b, int c)
    {
        long long int st = 1, end = 2e9, res = 2e9;
        while (st <= end)
        {
            long long int mid = st + (end - st) / 2;
            long long int count = mid / a + mid / b + mid / c - mid / lcm(a, b) - mid / lcm(b, c) -
                                  mid / lcm(c, a) + mid / (lcm(a, lcm(b, c)));
            if (count < n)
                st = mid + 1;
            else
            {
                end = mid - 1;
                res = mid;
            }
        }
        return res;
    }
};