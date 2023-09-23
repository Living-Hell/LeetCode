// M1
// Using Brute Force
// Faster than 5.23% (1504 ms)

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> f1(26, 0), f2(26, 0);
        for (const char &c : s1)
            f1[c - 'a']++;
        int l = 0, r = 0;
        while (r < n2)
        {
            f2[s2[r] - 'a']++;
            if (r - l + 1 == n1)
            {
                if (f1 == f2)
                    return 1;
            }
            if (r - l + 1 < n1)
            {
                r++;
            }
            else
            {
                f2[s2[l] - 'a']--;
                l++;
                r++;
            }
        }
        return 0;
    }
};

// M2
// Using 2-Pointers and frequency table
// Faster than 95.54% (3ms)

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> f1(26, 0), f2(26, 0);
        for (const char &c : s1)
            f1[c - 'a']++;
        int l = 0, r = 0;
        while (r < n2)
        {
            f2[s2[r] - 'a']++;
            if (r - l + 1 == n1)
            {
                if (f1 == f2)
                    return 1;
            }
            if (r - l + 1 < n1)
            {
                r++;
            }
            else
            {
                f2[s2[l] - 'a']--;
                l++;
                r++;
            }
        }
        return 0;
    }
};

// M3
// Using 2-Pointers and frequency table
// Faster than 56.11% (8ms)

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2)
            return 0;
        vector<int> f1(26, 0), f2(26, 0);
        for (int i = 0; i < n1; i++)
        {
            f1[s1[i] - 'a']++;
            f2[s2[i] - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
            count += (f1[i] == f2[i]);
        int l = 0, r = n1;
        while (r < n2)
        {
            if (count == 26)
                return 1;
            int c = s2[r] - 'a';
            f2[c]++;
            if (f1[c] == f2[c])
                count++;
            else if (f1[c] == f2[c] - 1)
                count--;

            c = s2[l] - 'a';
            f2[c]--;
            if (f1[c] == f2[c])
                count++;
            else if (f1[c] == f2[c] + 1)
                count--;

            l++, r++;
        }
        return count == 26;
    }
};