// M1
// Using Brute force + set
// Faster than 5.09% (2773 ms)

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        unordered_set<string> st(words.begin(), words.end());
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            string s = words[i];
            if (st.count(s) == 0)
                continue;
            bool check = 0;
            for (int j = 0; j < n; j++)
            {
                string s1 = words[j];
                if (i == j or s == s1)
                    continue;
                if (s1[s1.size() - 1] == s[s.size() - 1])
                {
                    int t1 = s.size() - 1, t2 = s1.size() - 1;
                    while (t1 >= 0 and t2 >= 0 and s[t1] == s1[t2])
                        t1--, t2--;
                    if (t1 == -1)
                    {
                        st.erase(s);
                        check = 1;
                        break;
                    }
                }
                if (check)
                    break;
            }
        }
        int ans = 0;
        for (string s : st)
            ans += s.size();
        ans += st.size();
        return ans;
    }
};