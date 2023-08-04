// M1
// Using binary search
// Faster than 29.17% (218ms)

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                int sum = nums[i] + nums[j];
                int low = j + 1, high = n, temp = -1;
                while (low < high)
                {
                    int mid = (high + low) / 2;
                    if (nums[mid] < sum)
                    {
                        low = mid + 1;
                        temp = mid;
                    }
                    else
                    {
                        high = mid;
                    }
                }
                if (temp != -1)
                    ans += temp - j;
            }
        }
        return ans;
    }
};

// M2
// Using 2 pointer (similar to 3 sum)
// Faster than 92.98% (79 ms)

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0, k = i - 1; j < k;)
            {
                if (nums[j] + nums[k] > nums[i])
                {
                    ans += k - j;
                    k--;
                }
                else
                    j++;
            }
        }
        return ans;
    }
};