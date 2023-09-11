// M1
// Using Binary Search
// Faster than 21.47% (20ms)

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int low = 0, high = n;
        while (low < high)
        {
            int mid = (low + high) >> 1;
            if (citations[mid] > n - mid)
                high = mid;
            else if (citations[mid] < n - mid)
                low = mid + 1;
            else
                return n - mid;
        }
        return n - low;
    }
};