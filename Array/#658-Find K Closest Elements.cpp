// M1
// Using sorting and lambda function
// Faster than 32.85% (63ms)

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end(), [&](const int &a, const int &b)
             {
            if(abs(x-a)<abs(x-b))
                return true;
            else if(abs(x-a)==abs(x-b))
                return a<b;
            return false; });
        for (int i = 0; i < k; i++)
        {
            ans.push_back(arr[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// M1
// Using priority queue
// Faster than 38.95% (55ms)
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ans;
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({abs(arr[i] - x), arr[i]});
        }
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};