// M1
// Using 2 pointers
// Faster than 61.4% (227ms)

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        long long int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int j = i + 1, k = n - 1;
            int val = target - arr[i];
            while (j < k)
            {
                if (arr[j] + arr[k] < val)
                    j++;
                else if (arr[j] + arr[k] > val)
                    k--;
                else
                {
                    int l = j, r = k;
                    int count1 = 0, count2 = 0;

                    while (l <= k and arr[l] == arr[j])
                    {
                        count1++;
                        l++;
                    }

                    if (l > k)
                    {
                        ans += count1 * (count1 - 1) / 2;
                    }

                    else
                    {
                        while (r >= l and arr[k] == arr[r])
                        {
                            count2++;
                            r--;
                        }
                        ans += count1 * count2;
                    }
                    j = l;
                    k = r;
                }
            }
        }
        return ans % 1000000007;
    }
};