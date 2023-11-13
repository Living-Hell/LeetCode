// M1
// Using Trie
// Faster than 100% (0ms)

class Solution
{
public:
    class Trie
    {
    public:
        Trie *child[26];
        bool eow;
        Trie()
        {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
            eow = 0;
        }
    };
    void insert(string s, Trie *root)
    {
        Trie *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            int ind = s[i] - 'a';
            if (temp->child[ind] == NULL)
            {
                temp->child[ind] = new Trie();
            }
            temp = temp->child[ind];
        }
        temp->eow = 1;
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        Trie *node = new Trie();
        for (string str : strs)
            insert(str, node);
        string ans;
        while (!node->eow)
        {
            int count = 0, nexti = -1;
            for (int i = 0; i < 26; i++)
            {
                if (node->child[i] != NULL)
                {
                    count++;
                    nexti = i;
                }
            }
            if (count > 1)
                return ans;
            if (nexti == -1)
                break;
            ans.push_back(nexti + 'a');
            node = node->child[nexti];
        }
        return ans;
    }
};