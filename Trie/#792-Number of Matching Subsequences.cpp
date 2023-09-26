// M1
// Using trie and hashmap
// Faster than 23.42% (421 ms)

class TrieNode
{
public:
    TrieNode *next[26];
    int end;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
        end = 0;
    }
};
class Trie
{
public:
    unordered_map<string, int> mp;
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string s)
    {
        TrieNode *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            int ind = s[i] - 'a';
            if (temp->next[ind] == NULL)
                temp->next[ind] = new TrieNode();
            temp = temp->next[ind];
        }
        temp->end = mp[s];
    }
    int findMatch(TrieNode *root, string s, int ind, vector<int> indexes[])
    {
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (root->next[i] != NULL)
            {
                int nexti = upper_bound(indexes[i].begin(), indexes[i].end(), ind) - indexes[i].begin();
                if (nexti == indexes[i].size())
                    continue;
                count += findMatch(root->next[i], s, indexes[i][nexti], indexes);
            }
        }
        return count + root->end;
    }
};
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        Trie *t = new Trie();
        for (const string &s : words)
            t->mp[s]++;
        for (auto i : t->mp)
            t->insert(i.first);
        vector<int> indexes[26];
        for (int i = 0; i < s.size(); i++)
            indexes[s[i] - 'a'].push_back(i);
        return t->findMatch(t->root, s, -1, indexes);
    }
};