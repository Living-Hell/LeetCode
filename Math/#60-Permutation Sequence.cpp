// M1
// Using math and factorial
// Faster than 100% (0ms)

class Solution
{
public:
    int factorial(int n)
    {
        return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
    }
    string getPermutation(int n, int k)
    {
        k--;
        vector<int> dig;
        for (int i = 1; i <= n; i++)
            dig.push_back(i);
        string ans;
        int fact;
        while (ans.size() < n)
        {
            int n1 = dig.size() - 1;
            fact = factorial(n1);
            int ind = k / fact;
            k = k % fact;
            ans.push_back(dig[ind] + '0');
            dig.erase(dig.begin() + ind);
        }
        return ans;
    }
};