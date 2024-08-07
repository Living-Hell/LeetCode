// M1
// Using Simulaton and Iteration
// Faster than 86.16% (15ms)

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        int res = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int count1 = 0, count2 = 0, j = i - 1, num = rating[i];
            while (j >= 0)
            {
                if (rating[j] > num)
                    count1++;
                j--;
            }
            j = i + 1;
            while (j < n)
            {
                if (num > rating[j])
                    count2++;
                j++;
            }
            res += count1 * count2;
            res += (i - count1) * (n - i - 1 - count2);
        }
        return res;
    }
};