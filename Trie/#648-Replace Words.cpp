// M1
// Using Trie
// Faster than 50% (184ms)

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
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
            eow = 0;
        }
    };
    void insert(TrieNode *root, string s)
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
    string find(TrieNode *root, string s)
    {
        string ans = "";
        TrieNode *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            int ind = s[i] - 'a';
            if (temp->next[ind] != NULL)
            {
                ans.push_back(s[i]);
                temp = temp->next[ind];
                if (temp->eow)
                    return ans;
            }
            else
                return s;
        }
        return ans;
    }
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        TrieNode *root = new TrieNode();
        for (const string &s : dictionary)
            insert(root, s);
        vector<string> sentences;
        string temp = "";
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                sentences.push_back(temp);
                temp = "";
            }
            else
                temp.push_back(sentence[i]);
        }
        sentences.push_back(temp);
        string ans = "";
        for (const string &s : sentences)
            ans = ans + find(root, s) + " ";
        ans.pop_back();
        return ans;
    }
};