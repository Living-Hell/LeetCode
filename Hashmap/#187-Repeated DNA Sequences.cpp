// M1
// Using rolling hashing
// Faster than 97.63% (30ms)

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        // long long mod = 5381;
        int n = s.size();
        vector<string> ans;
        unordered_map<long long, int> mp;
        long long int hash_val = 0;
        int val[n];
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
                val[i] = 0;
            else if (s[i] == 'G')
                val[i] = 1;
            else if (s[i] == 'C')
                val[i] = 2;
            else if (s[i] == 'T')
                val[i] = 3;
        }
        for (int i = 0; i < n - 9; i++)
        {
            if (i == 0)
            {
                for (int i = 0; i < 10; i++)
                {
                    hash_val = 4 * hash_val + val[i];
                }
                mp[hash_val]++;
            }
            else
            {
                hash_val = hash_val * 4 - pow(4, 10) * val[i - 1] + val[i + 9];
                mp[hash_val]++;
                if (mp[hash_val] == 2)
                    ans.push_back(s.substr(i, 10));
            }
        }
        return ans;
    }
};