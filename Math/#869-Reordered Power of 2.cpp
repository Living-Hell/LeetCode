// M1
// Using backtracking
// Faster than 5.26% (451ms)

class Solution
{
public:
    bool checker(int n)
    {
        return (n & (n - 1)) == 0;
    }
    bool ans = 0;
    void solve(int ind, string &num)
    {
        if (ind == num.size())
        {
            if (num[0] != '0' and checker(stoi(num)))
                ans = 1;
            return;
        }

        for (int i = ind; i < num.size(); i++)
        {
            swap(num[ind], num[i]);
            solve(ind + 1, num);
            swap(num[ind], num[i]);
        }
    }
    bool reorderedPowerOf2(int n)
    {
        string num = to_string(n);
        solve(0, num);
        return ans;
    }
};

// M2
// Using sorting
// Faster than 100% (0ms)

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string num = to_string(n);
        sort(num.begin(), num.end());
        for (int i = 0; i < 32; i++)
        {
            string temp = to_string(1 << i);
            sort(temp.begin(), temp.end());
            if (num == temp)
                return 1;
        }
        return 0;
    }
};