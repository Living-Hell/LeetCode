// M1
// Using precomputation and maths
// Faster than 6.69% (2163 ms)

class NumArray
{
public:
    vector<int> v;
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        v.resize(n);
        v[0] = nums[0];
        for (int i = 1; i < n; i++)
            v[i] = v[i - 1] + nums[i];
    }

    void update(int index, int val)
    {
        int curr = index > 0 ? v[index] - v[index - 1] : v[index];
        int change = val - curr;
        for (int i = index; i < v.size(); i++)
            v[i] += change;
    }

    int sumRange(int left, int right)
    {
        return left > 0 ? v[right] - v[left - 1] : v[right];
    }
};
