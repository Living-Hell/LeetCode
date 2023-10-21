// M1
// Using set and a little bit of math
// Faster than 100% (0ms)

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        set<int> st;
        int i = 0;
        vector<int> ans;

        if (x == 1 and y == 1)
        {
            if (2 <= bound)
                ans.push_back(2);
            return ans;
        }

        if (x > y)
            swap(x, y);

        if (x == 1)
        {
            int i = 0;
            while (pow(y, i) <= bound)
            {
                int val = 1 + pow(y, i);
                if (val <= bound)
                    ans.push_back(val);
                i++;
            }
            return ans;
        }

        while (pow(y, i) <= bound)
        {
            for (int k = 0; pow(x, k) + pow(y, i) <= bound; k++)
            {
                int val = pow(x, k) + pow(y, i);
                st.insert(val);
            }
            i++;
        }

        ans.insert(ans.begin(), st.begin(), st.end());

        return ans;
    }
};