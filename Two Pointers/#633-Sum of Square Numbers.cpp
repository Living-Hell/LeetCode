// M1
// Using Two Pointers
// Faster than 100% (0ms)

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long low = 0, high = sqrt(c);
        while (low <= high)
        {
            long sum = (low * low) + (high * high);
            if (sum == c)
                return 1;
            if (sum > c)
                high--;
            else
                low++;
        }
        return 0;
    }
};

// M2
// Using Binary Search
// Faster than 11.48% (27ms)

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (int i = 0; i <= sqrt(c); i++)
        {
            long low = i, high = sqrt(c);
            while (low <= high)
            {
                long mid = (low + high) / 2; // cout<<i<<" : "<<mid<<endl;
                if ((i * i) + (mid * mid) < c)
                    low = mid + 1;
                else if ((i * i) + (mid * mid) > c)
                    high = mid - 1;
                else
                    return 1;
            }
        }
        return 0;
    }
};
