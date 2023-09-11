// M1
// Using brute force-counting
// Faster than 47.99% (3ms)

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int cit[1001] = {0};
        int ans = 0;
        for (int i : citations)
        {
            for (int j = 0; j <= i; j++)
            {
                cit[j]++;
                if (cit[j] >= j)
                    ans = j;
            }
        }
        return ans;
    }
};