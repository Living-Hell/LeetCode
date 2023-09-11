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

// M2
// Using Sorting
// Faster than 42.5% (4ms)

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size(), i;
        for (i = 0; i < n; i++)
        {
            if (citations[i] <= i)
                return i;
        }
        return i;
    }
};
