// M1
// Using two-pointers
// Faster than 29.51% (5ms)

class Solution
{
public:
    void merge(vector<int> &nums1, int n, vector<int> &nums2, int m)
    {
        vector<int> copy(nums1.begin(), nums1.begin() + n);
        int i = 0, j = 0, ind = 0;
        while (i < n and j < m)
        {
            if (copy[i] < nums2[j])
            {
                nums1[ind++] = copy[i++];
            }
            else
            {
                nums1[ind++] = nums2[j++];
            }
        }
        while (i < n)
            nums1[ind++] = copy[i++];
        while (j < m)
            nums1[ind++] = nums2[j++];
    }
};

// M2
// Using 2 pointers
// Faster than 100% (0ms)

class Solution
{
public:
    void merge(vector<int> &nums1, int n, vector<int> &nums2, int m)
    {
        int i = n - 1, j = m - 1, ind = n + m - 1;
        while (i >= 0 and j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[ind--] = nums1[i--];
            }
            else
            {
                nums1[ind--] = nums2[j--];
            }
        }
        while (j >= 0)
            nums1[ind--] = nums2[j--];
    }
};