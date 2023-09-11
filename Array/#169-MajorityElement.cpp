// M1
// Using 2-pointers
// Faster than 80.64%(26ms)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int start = 0, end = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        while (end < n)
        {
            while (nums[start] == nums[end])
            {
                end++;
                if ((end - start) > n / 2)
                    return nums[start];
            }
            start = end;
        }

        return nums[end];
    }
};

// M2
// Using Moore-Voter's Algorithm
// Faster than 87.7%(11ms)

class Solution
{
public:
    int majorityElement(vector<int> &a)
    {
        int count = 0, el;
        for (int i = 0; i < a.size(); i++)
        {
            if (count == 0)
            {
                el = a[i];
                count++;
            }
            else if (a[i] != el)
                count--;
            else
                count++;
        }
        count = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == el)
                count++;
            if (count > a.size() / 2)
                return el;
        }
        return -1;
    }
};