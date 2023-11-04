// M1
// Using DFS
// Faster than 72.21% (32 ms)

class Solution
{
public:
    bool solve(vector<int> &arr, int ind, vector<bool> &vis)
    {
        if (ind < 0 or ind >= arr.size() or vis[ind])
            return 0;
        if (arr[ind] == 0)
            return 1;
        vis[ind] = 1;
        if (solve(arr, ind + arr[ind], vis) or solve(arr, ind - arr[ind], vis))
            return 1;
        return 0;
    }
    bool canReach(vector<int> &arr, int start)
    {
        vector<bool> vis(arr.size(), 0);
        return solve(arr, start, vis);
    }
};