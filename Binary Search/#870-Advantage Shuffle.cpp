// M1
// Using Binary Search and multiset
// Faster than 30.57% (176ms)

class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        multiset<int> st(nums1.begin(), nums1.end());

        for (int i = 0; i < n; i++)
        {
            int temp = nums2[i];
            auto it = st.upper_bound(temp);
            if (it != st.end())
            {
                nums1[i] = *it;
                st.erase(it);
            }
            else
                nums1[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums1[i] == -1)
            {
                nums1[i] = *st.begin();
                st.erase(st.begin());
            }
        }
        return nums1;
    }
};