// M1
// Using simulation and 2 pointers
// Faster than 9.8% (3ms)

class Solution
{
public:
    bool isStrictlyPalindromic(int n)
    {
        for (int i = 2; i <= n - 2; i++)
        {
            string pal = "";
            int temp = n;
            while (temp > 0)
            {
                char c = temp % i + '0';
                pal.push_back(c);
                temp /= i;
            }
            for (int st = 0, end = pal.size() - 1; st < (pal.size() + 1) / 2; st++, end--)
                if (pal[st] != pal[end])
                    return 0;
        }
        return 1;
    }
};

// M2
// Return false
// Faster than 100% (0ms)

class Solution
{
public:
    bool isStrictlyPalindromic(int n)
    {
        return false;
    }
};