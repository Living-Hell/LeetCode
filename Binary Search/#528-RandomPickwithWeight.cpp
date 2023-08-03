// M1
// Using prefix sum and binary search
// Faster than 91.21% (79ms)

class Solution
{
public:
    vector<int> v;
    int n;
    Solution(vector<int> &w)
    {
        n = w.size();
        v.resize(n);
        v[0] = w[0];
        for (int i = 1; i < n; i++)
            v[i] = w[i] + v[i - 1];
    }

    // DO the same using binary search

    int pickIndex()
    {
        int sum = v[n - 1];
        int ind = rand() % sum;
        int low = 0, high = n;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (v[mid] > ind)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */