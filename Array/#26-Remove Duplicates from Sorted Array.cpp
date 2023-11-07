// M1
// Using unordered sets
// Faster than 42.75% (11ms)

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        unordered_set<int> st;
        int ind = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (!st.count(nums[i]))
            {
                nums[ind++] = nums[i];
                st.insert(nums[i]);
            }
        }
        return ind;
    }
};

// M2
// Using unordered sets
// Faster than 86.82% (4ms)

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int ind = 1, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[ind++] = nums[i];
            }
        }
        return ind;
    }
};