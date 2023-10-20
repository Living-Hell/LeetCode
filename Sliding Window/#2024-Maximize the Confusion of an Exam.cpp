// M1
// Using sliding window
// Faster than 77.17% (22ms)

class Solution
{
public:
    int maxConsecutiveAnswers(string s, int k)
    {
        int n = s.size();
        int i = 0, j = 0, ans = 0;
        int ft = 0, ff = 0;
        while (j < n)
        {
            if (s[j] == 'T')
                ft++;
            else
                ff++;
            int maxf = max(ft, ff);
            if (j - i + 1 - maxf > k)
            {
                while (j - i + 1 - maxf > k)
                {
                    if (s[i] == 'T')
                        ft--;
                    else
                        ff--;
                    i++;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};