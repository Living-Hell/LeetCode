// M1
// Using Brute Force

class Solution
{
public:
    int strStr(string haystack, string needle)
    {

        if (needle.length() > haystack.length())
            return -1;

        for (int i = 0; i <= haystack.length() - needle.length(); i++)
        {

            int j;
            for (j = 0; j < needle.length(); j++)
            {

                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }

            if (j == needle.length())
                return i;
        }

        return -1;
    }
};

// M2
// Using Z-Algorithm
// Faster than 100% (0ms)

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        haystack = needle + "$" + haystack;
        int n = haystack.size();
        vector<int> z(n);
        z[0] = 0;
        int left = 0, right = 0;
        for (int i = 1; i < n; i++)
        {
            if (i > right)
            {
                left = right = i;
                while (right < n and haystack[right] == haystack[right - left])
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
                    while (right < n and haystack[right] == haystack[right - left])
                        right++;
                    z[i] = right - left;
                    right--;
                }
            }
        }
        int nl = needle.size();
        for (int i = 0; i < n; i++)
        {
            if (z[i] == nl)
                return i - nl - 1;
        }
        return -1;
    }
};