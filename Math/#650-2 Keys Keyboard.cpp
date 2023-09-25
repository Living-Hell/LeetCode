// M1
// Using maths
// Faster than 67.24% (3ms)

class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return i + minSteps(n / i);
        }
        return n;
    }
};