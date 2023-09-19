// M1
// Using Z-Algo
// Faster than 84.96% (4ms)

class Solution
{
public:
    bool zAlgo(string a, string b)
    {
        a = b + "#" + a;
        int n = a.size();
        vector<int> z(n);
        z[0] = 0;
        int left = 0, right = 0;
        for (int i = 1; i < n; i++)
        {
            if (i > right)
            {
                left = right = i;
                while (right < n and a[right] == a[right - left])
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
                    while (right < n and a[right] == a[right - left])
                        right++;
                    z[i] = right - left;
                    right--;
                }
            }
        }

        for (int i = b.size() + 1; i < n; i++)
            if (z[i] == b.size())
                return 1;
        return 0;
    }
    int repeatedStringMatch(string a, string b)
    {
        int ans;
        string t = a;
        ans = ceil(b.size() / (float)a.size());
        for (int i = 1; i < ans; i++)
            a += t;
        if (zAlgo(a, b))
            return ans;
        a += t;
        ans++;
        if (zAlgo(a, b))
            return ans;
        return -1;
    }
};