// M1
// Using iterative approach
// Faster than 25.85% (8ms)

class Solution
{
public:
    int lastRemaining(int n)
    {
        int st = 1, diff = 1, tn = n;
        bool l2r = 1;
        while (tn > 1)
        {
            if (l2r or tn & 1)
                st += diff;
            diff *= 2;
            tn /= 2;
            l2r ^= 1;
        }
        return st;
    }
};

// M2
// Using recursion
// Faster than 100% (0ms)

class Solution
{
public:
    int solve(int n)
    {
        if (n <= 2)
            return n - 1;
        if (n & 1)
            return n - 2 - 2 * solve(n / 2);
        else
            return n - 1 - 2 * solve(n / 2);
    }
    int lastRemaining(int n)
    {
        return solve(n) + 1;
    }
};