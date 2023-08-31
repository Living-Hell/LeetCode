// M1
// Using Z-Algorithm
// Faster than 37.27% (389ms)

class Solution
{
public:
    long long sumScores(string s)
    {
        int n = s.size();
        vector<int> z(n);
        z[0] = n;
        int left = 0, right = 0;
        for (int i = 1; i < n; i++)
        {
            if (i > right)
            {
                left = right = i;
                while (right < n and s[right] == s[right - left])
                    right++;
                z[i] = right - left;
                right--;
            }
            else
            {
                int k = i - left;
                if (z[k] < right - i + 1)
                    z[i] = z[k];
                else
                {
                    left = i;
                    while (right < n and s[right] == s[right - left])
                        right++;
                    z[i] = right - left;
                    right--;
                }
            }
        }
        long long ans = 0;
        for (auto i : z)
        {
            cout << i << " ";
            ans += i;
        }
        return ans;
    }
};