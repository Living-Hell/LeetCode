// M1
// Using Simultaion and math
// Faster than 37.1% (4ms)

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> ans;
        int i = 1, j = k + 1;
        while (i <= j)
        {
            if (i == j)
                ans.push_back(i);
            else
            {
                ans.push_back(i);
                ans.push_back(j);
            }
            i++, j--;
        }
        for (int i = k + 2; i <= n; i++)
            ans.push_back(i);
        return ans;
    }
};