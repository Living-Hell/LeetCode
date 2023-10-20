// M1
// Using sliding window and frequency table
// Faster than 87.04% (4ms)

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int i = 0, j = 0, ans = 0;
        int a[26] = {0};
        while (j < n)
        {
            a[s[j] - 'A']++;
            int maxf = 0;
            for (int i = 0; i < 26; i++)
                maxf = max(maxf, a[i]);
            if (j - i + 1 - maxf > k)
            {
                while (j - i + 1 - maxf > k)
                    a[s[i++] - 'A']--;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

// M2
// Using sliding window and frequency table
// Faster than 84.44% (6ms)
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int i = 0, j = 0, ans = 0;
        int a[26] = {0};
        int maxf = 0;
        while (j < n)
        {
            a[s[j] - 'A']++;
            maxf = max(maxf, a[s[j] - 'A']);
            if (j - i + 1 - maxf > k)
            {
                while (j - i + 1 - maxf > k)
                    a[s[i++] - 'A']--;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};