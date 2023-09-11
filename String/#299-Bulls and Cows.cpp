// M1
// Using hashmap
// Faster than 59.22% (4ms)

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int x = 0, y = 0;
        int n = secret.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] != guess[i])
                mp[secret[i]]++;
            else
                x++;
        }
        for (int i = 0; i < n; i++)
        {
            if (secret[i] != guess[i])
            {
                if (mp.find(guess[i]) != mp.end())
                {
                    if (mp[guess[i]] > 0)
                    {
                        y++;
                        mp[guess[i]]--;
                    }
                    if (mp[guess[i]] == 0)
                        mp.erase(guess[i]);
                }
            }
        }
        string ans = to_string(x) + "A" + to_string(y) + "B";
        return ans;
    }
};