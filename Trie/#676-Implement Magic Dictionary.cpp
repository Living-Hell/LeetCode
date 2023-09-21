// M1
// Using Trie
// Faster than 47.35% (173 ms)

class MagicDictionary
{
public:
    class TrieNode
    {
    public:
        TrieNode *next[26];
        bool eow;
    };
    TrieNode *root = new TrieNode;

    MagicDictionary()
    {
        for (int i = 0; i < 26; i++)
            root->next[i] = NULL;
        root->eow = 0;
    }

    void buildDict(vector<string> dictionary)
    {
        for (const string &s : dictionary)
        {
            TrieNode *temp = root;
            for (int i = 0; i < s.size(); i++)
            {
                int ind = s[i] - 'a';
                if (temp->next[ind] == NULL)
                    temp->next[ind] = new TrieNode();
                temp = temp->next[ind];
            }
            temp->eow = 1;
        }
    }

    bool find(TrieNode *root, string word, int ind, int diff)
    {
        if (diff < 0)
            return 0;
        if (ind == word.size())
            return (root->eow and diff == 0);
        for (int i = 0; i < 26; i++)
        {
            if (root->next[i] != NULL)
                if (find(root->next[i], word, ind + 1, diff - ((word[ind] - 'a') != i)))
                    return 1;
        }
        return 0;
    }

    bool search(string searchWord)
    {
        return find(root, searchWord, 0, 1);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */