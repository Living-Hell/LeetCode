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

// M2
// Using sorting and lambda function
// Faster than 89.45% (34ms)

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), [&](const string &a, const string &b)
             {
                for(auto ia = a.rbegin(), ib = b.rbegin(); ia!= a.rend() and ia != b.rend(); ia++, ib++)
                    if(*ia != *ib)
                        return *ia < *ib;
                return a.size() < b.size(); });
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans += words[i].size() <= words[i + 1].size() and
                           words[i] == words[i + 1].substr(words[i + 1].size() - words[i].size())
                       ? 0
                       : words[i].size() + 1;
        }
        return ans + words[n - 1].size() + 1;
    }
};