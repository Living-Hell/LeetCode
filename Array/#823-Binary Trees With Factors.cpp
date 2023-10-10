// M1
// Using hashmap and sorting
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