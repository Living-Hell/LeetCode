// M1
// Using Radix Sort
// Faster than 79.27% (128ms)

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxe = *max_element(nums.begin(), nums.end()) + 50000;
        int div = 1;

        for (int i = 0; i < n; i++)
            nums[i] += 50000;

        while ((maxe / div) >= 1)
        {
            vector<int> ans(n);
            vector<int> count(10, 0);

            for (int num : nums)
                count[(num / div) % 10]++;

            for (int i = 1; i < 10; i++)
                count[i] += count[i - 1];

            for (int i = n - 1; i >= 0; i--)
            {
                int num = (nums[i] / div) % 10;
                ans[count[num] - 1] = nums[i];
                count[num]--;
            }

            for (int i = 0; i < n; i++)
                nums[i] = ans[i];

            div *= 10;
        }

        for (int i = 0; i < n; i++)
            nums[i] -= 50000;
        return nums;
    }
};

// M2
// Using Heap
// Faster than 73% (151ms)

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums)
            pq.push(num);
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
