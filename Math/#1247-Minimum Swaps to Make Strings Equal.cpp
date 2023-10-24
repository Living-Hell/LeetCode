// M1
// Using maths
// Faster than 49.51% (3ms)

class Solution
{
public:
    int minimumSwap(string s1, string s2)
    {
        int n = s1.size();
        int swaps = 0, countx = 0, county = 0;

        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[i])
                continue;
            if (s1[i] == 'x')
                countx++;
            else
                county++;
        }

        if ((countx + county) & 1)
            return -1;

        swaps += (countx + county) / 2;

        if (countx & 1)
            swaps += 1;

        return swaps;
    }
};