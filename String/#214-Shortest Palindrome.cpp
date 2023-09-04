// M1
// Using Z Algorithm
// Faster than 18.91% (13ms)

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        int len = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        t = s + "#" + t;
        int n = t.size();
        vector<int> z(n);
        z[0] = 0;
        int left = 0, right = 0;
        for (int i = 1; i < n; i++)
        {
            if (i > right)
            {
                left = right = i;
                while (right < n and t[right] == t[right - left])
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
                    while (right < n and t[right] == t[right - left])
                        right++;
                    z[i] = right - left;
                    right--;
                }
            }
        }
        cout << t;
        string temp = "";
        for (int i = len + 1; i < n; i++)
        {
            if (z[i] + i == n)
            {
                int ind = len - 1, to_add = i - len - 1;
                while (to_add--)
                    temp.push_back(s[ind--]);
                break;
            }
        }
        return temp + s;
    }
};