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