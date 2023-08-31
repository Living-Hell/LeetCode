// M1
// Using Z-Algorithm
// Faster than 36.41% (44ms)

class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.size();
        vector<int> z(n);
        z[0] = 0;
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
        for (int i = 0; i < n; i++)
        {
            if (z[i] + i == n)
                return s.substr(i, z[i]);
        }
        return "";
    }
};