// M1
// Using Frequency Table
// Faster than 96.43% (87ms)

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        int freq[26] = {0};
        for (string s : words2)
        {
            int a[26] = {0};
            for (char c : s)
            {
                a[c - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                freq[i] = max(freq[i], a[i]);
            }
        }

        vector<string> ans;
        for (string s : words1)
        {
            int a[26] = {0};
            for (char c : s)
            {
                a[c - 'a']++;
            }
            bool check = 1;
            for (int i = 0; i < 26; i++)
            {
                if (freq[i] > a[i])
                {
                    check = 0;
                    break;
                }
            }
            if (check)
                ans.push_back(s);
        }
        return ans;
    }
};