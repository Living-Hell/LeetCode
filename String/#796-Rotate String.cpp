// M1
// Using Z Algo
// Faster than 100% (0ms)

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (goal.size() != s.size())
            return 0;
        goal = s + "#" + goal + goal;
        int n = goal.size();
        vector<int> z(n);
        z[0] = 0;
        int left = 0, right = 0;
        for (int i = 1; i < n; i++)
        {
            if (i > right)
            {
                left = right = i;
                while (right < n and goal[right] == goal[right - left])
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
                    while (right < n and goal[right] == goal[right - left])
                        right++;
                    z[i] = right - left;
                    right--;
                }
            }
        }
        for (int i : z)
            if (i == (int)s.size())
                return 1;
        return 0;
    }
};