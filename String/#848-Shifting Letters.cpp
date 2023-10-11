// M1
// Using prefix sum
// Faster than 97.13% (90ms)

class Solution
{
public:
    string shiftingLetters(string s, vector<int> &shifts)
    {
        int n = s.size();
        vector<long long int> pref(n);
        pref[n - 1] = shifts[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            pref[i] = pref[i + 1] + shifts[i];
        }
        for (int i = 0; i < n; i++)
        {
            int curr = s[i] - 'a';
            s[i] = (curr + pref[i]) % 26 + 'a';
        }
        return s;
    }
};