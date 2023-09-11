// M1
// Using Moore-Voter's ALgo
// Faster than 61.65% (11ms)

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int count1 = 0, count2 = 0, el1 = INT_MIN, el2 = INT_MIN;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el1)
                count1++;
            else if (nums[i] == el2)
                count2++;
            else if (count1 == 0)
            {
                el1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                el2 = nums[i];
                count2 = 1;
            }
            else
                count1--, count2--;
        }
        count1 = count2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el1)
                count1++;
            if (nums[i] == el2)
                count2++;
        }
        if (count1 > n / 3)
            ans.push_back(el1);
        if (count2 > n / 3)
            ans.push_back(el2);
        return ans;
    }
};