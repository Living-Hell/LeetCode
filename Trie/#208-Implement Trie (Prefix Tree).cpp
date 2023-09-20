// M1
// Trie Implementation
// Faster than 65.16% (50ms)

class Trie
{
public:
    class TrieNode
    {
    public:
        TrieNode *next[26];
        bool eow;
    };
    TrieNode *root = new TrieNode;
    Trie()
    {
        for (int i = 0; i < 26; i++)
            root->next[i] = NULL;
        root->eow = 0;
    }

    void insert(string word)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            int ind = word[i] - 'a';
            if (temp->next[ind] == NULL)
                temp->next[ind] = new TrieNode();
            temp = temp->next[ind];
        }
        temp->eow = 1;
    }

    bool search(string word)
    {
        TrieNode *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            int ind = word[i] - 'a';
            if (temp->next[ind] != NULL)
                temp = temp->next[ind];
            else
                return 0;
        }
        return temp->eow;
    }

    bool startsWith(string prefix)
    {
        TrieNode *temp = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int ind = prefix[i] - 'a';
            if (temp->next[ind] == NULL)
                return 0;
            temp = temp->next[ind];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */