// M1
// Using modulus and brute force
// Faster than 78.69% (15 ms)

class Solution
{
public:
    string largestMultipleOfThree(vector<int> &digits)
    {
        int sum = accumulate(digits.begin(), digits.end(), 0);
        int n = digits.size();
        sort(digits.begin(), digits.end());
        if (sum % 3 == 1)
        {
            bool check1 = 1;
            for (int i = 0; i < n; i++)
            {
                if (digits[i] % 3 == 1)
                {
                    digits[i] = -1;
                    check1 = 0;
                    break;
                }
            }
            if (check1)
            {
                int count = 2;
                for (int i = 0; i < n; i++)
                {
                    if (digits[i] % 3 == 2)
                    {
                        digits[i] = -1;
                        count--;
                        if (count == 0)
                            break;
                    }
                    if (!count)
                        break;
                }
                if (count)
                    return "";
            }
        }
        else if (sum % 3 == 2)
        {
            bool check1 = 1;
            for (int i = 0; i < n; i++)
            {
                if (digits[i] % 3 == 2)
                {
                    digits[i] = -1;
                    check1 = 0;
                    break;
                }
            }
            if (check1)
            {
                int count = 2;
                for (int i = 0; i < n; i++)
                {
                    if (digits[i] % 3 == 1)
                    {
                        digits[i] = -1;
                        count--;
                        if (count == 0)
                            break;
                    }
                    if (!count)
                        break;
                }
                if (count)
                    return "";
            }
        }
        string ans;
        reverse(digits.begin(), digits.end());
        int zeros = 0;
        for (int i : digits)
        {
            if (i == 0)
                zeros++;
            else if (i != -1)
                ans.push_back(i + '0');
        }
        if (ans.size() == 0 and zeros)
            return "0";
        while (zeros--)
            ans.push_back('0');
        return ans;
    }
};