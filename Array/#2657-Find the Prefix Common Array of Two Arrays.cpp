// M1
// Using frequency table
// Faster than 94.4% (31ms)

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        vector<int> ans;
        vector<int> freq(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            if (freq[a[i]] == -1)
                freq[a[i]] = 1;
            else if (freq[a[i]] == 1)
                freq[a[i]] = 0;
            if (freq[b[i]] == -1)
                freq[b[i]] = 1;
            else if (freq[b[i]] == 1)
                freq[b[i]] = 0;
            int count = 0;
            for (int i = 0; i <= n; i++)
                if (freq[i] == 0)
                    count++;
            ans.push_back(count);
        }
        return ans;
    }
};