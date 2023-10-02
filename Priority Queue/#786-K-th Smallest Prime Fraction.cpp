// M1
// Using minHeap
// Faster than 52.5% (353 ms)

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<float, vector<float>, greater<float>> pq;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                pq.push(arr[i] / (float)arr[j]);
            }
        }
        while (--k)
            pq.pop();
        float ans = pq.top();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] / (float)arr[j] == ans)
                    return {arr[i], arr[j]};
            }
        }
        return {-1};
    }
};