// M1
// Using recursion
// Faster than 30.76% (92ms)

class Solution
{
public:
    int solve(vector<int> &grades, int ind, int prevSum, int prevSize)
    {
        int n = grades.size();
        if (ind >= n)
            return 0;
        int curr_sum = 0;
        if (n - ind <= prevSize)
            return 0;
        int i = ind;
        for (i = ind; i <= ind + prevSize; i++)
            curr_sum += grades[i];
        while (curr_sum <= prevSum)
            curr_sum += grades[i];
        return 1 + solve(grades, i, curr_sum, i - ind);
    }
    int maximumGroups(vector<int> &grades)
    {
        sort(grades.begin(), grades.end());
        return solve(grades, 0, 0, 0);
    }
};

// M2
// Using iterative approach
// Faster than 68.73% (70ms)

class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        int k = 0, total = 0, n = grades.size();
        while (total + k + 1 <= n)
            total += ++k;
        return k;
    }
};

// M3
// Using maths
// Faster than 99.49% (53ms)

class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        int n = grades.size();
        float ans = sqrt(2 * n + 0.25) - 0.5;
        return (int)ans;
    }
};