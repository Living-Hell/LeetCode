// M1
// Using trie
// Faster than 95.67% (30 ms)

class Solution
{
public:
    class TrieNode
    {
    public:
        TrieNode *next[26];
        bool eow;
        TrieNode()
        {
            eow = 0;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };
    void insert(string s, TrieNode *root)
    {
        int n = s.size();
        TrieNode *curr = root;
        for (int i = 0; i < n; i++)
        {
            int ind = s[i] - 'a';
            if (curr->next[ind] == NULL)
                curr->next[ind] = new TrieNode();
            curr = curr->next[ind];
        }
        curr->eow = 1;
    }
    bool check(string s, TrieNode *root)
    {
        TrieNode *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (temp == root or temp->eow)
                temp = temp->next[s[i] - 'a'];
            else
                return 0;
        }
        return 1;
    }
    string longestWord(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (const string &s : words)
            insert(s, root);
        string ans = "";
        for (const string &s : words)
        {
            if (check(s, root))
            {
                if (s.size() > ans.size() or (s.size() == ans.size() and s < ans))
                    ans = s;
            }
        }
        return ans;
    }
};