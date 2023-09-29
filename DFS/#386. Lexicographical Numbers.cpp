// M1
// Using maths and dfs
// Faster than 64.96% (9ms)

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans(n);
        int count = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] = count;
            if (count * 10 <= n)
                count *= 10;
            else
            {
                if (count >= n)
                    count /= 10;
                count++;
                while (count % 10 == 0)
                    count /= 10;
            }
        }
        return ans;
    }
};

// M2
// Using sorting
// Faster than 5.4% (202ms)

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            ans.push_back(i);
        sort(ans.begin(), ans.end(), [&](const int &a, const int &b)
             { return to_string(a) < to_string(b); });
        return ans;
    }
};