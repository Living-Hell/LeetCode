// M1
// Using dp, set and sorting
// Faster than 7.14% (126ms)

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        set<int> st(arr.begin(), arr.end());
        int n = arr.size();
        long long int ans = n, mod = 1e9 + 7;
        unordered_map<long long int, long long int> mp;

        sort(arr.begin(), arr.end());

        for (int i : arr)
            mp[i] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j or arr[i] < arr[j])
                    continue;

                int temp = arr[i] / arr[j];

                if (arr[j] * temp == arr[i] and st.count(temp))
                {
                    ans += mp[arr[j]] * mp[temp] % mod;
                    mp[arr[i]] += (mp[arr[j]] * mp[temp]) % mod;
                }
            }
        }
        return ans % mod;
    }
};

// M2
// Using dp and sorting
// Faster than 29.66% (66ms)

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int n = arr.size();
        long long int ans = 0, mod = 1e9 + 7;
        unordered_map<int, long long int> mp;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = 1;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0)
                {
                    int temp = arr[i] / arr[j];
                    mp[arr[i]] += (mp[arr[j]] * mp[temp]) % mod;
                }
            }
            ans = (ans + mp[arr[i]]) % mod;
        }
        return ans % mod;
    }
};