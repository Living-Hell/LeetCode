// M1
// Using Sets
// Faster than 51.25% (177 ms)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        set<int> st;
        for (int i : nums)
            st.insert(i);
        int count = 0, i = 0, j = 0, curr = *st.begin();
        for (auto s = st.begin(); s != st.end(); s++)
        {
            if (*s - curr == 1)
            {
                j++;
            }
            else
            {
                count = max(count, j - i + 1);
                i = j;
            }
            curr = *s;
        }
        count = max(count, j - i + 1);
        return count;
    }
};