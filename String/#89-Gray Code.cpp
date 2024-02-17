// M1
// Using property to generate gray code
// Faster than 7.45% (60ms)

class Solution
{
public:
    vector<string> solve(int n)
    {
        if (n == 1)
            return {"0", "1"};

        vector<string> res = solve(n - 1);
        int sz = res.size();

        for (int i = sz - 1; i >= 0; i--)
            res.push_back(res[i]);
        for (int i = 0; i < sz; i++)
            res[i].push_back('0');
        for (int i = sz; i < res.size(); i++)
            res[i].push_back('1');

        return res;
    }
    int toInt(string s)
    {
        int ans = 0, counter = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            ans += pow(2, counter) * (s[i] == '1');
            counter++;
        }
        return ans;
    }
    vector<int> grayCode(int n)
    {
        vector<string> v = solve(n);
        vector<int> ans;
        for (string s : v)
            ans.push_back(toInt(s));
        return ans;
    }
};

// M2
// Using bit operators
// Faster than 72.36% (4ms)

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> res(1 << n);
        for (int i = 0; i < (1 << n); i++)
        {
            res[i] = i ^ (i >> 1);
        }
        return res;
    }
};