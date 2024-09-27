//M1
//Using Trie + DFS + DP (recursion + memoisation)
//Faster than 72.56% (174 ms)

class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[26];
        bool isEod;
        TrieNode() {
            isEod = false;
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };
    int dp[10002];
    bool search(TrieNode* root, string& s, int ind, int count) {
        if (ind == s.size())
            return count >= 2;

        if (dp[ind] != -1)
            return dp[ind];

        TrieNode* temp = root;
        for (int i = ind; i < s.size(); i++) {
            char c = s[i];
            if (temp->child[c - 'a'] == NULL)
                return dp[ind] = false;

            temp = temp->child[c - 'a'];

            if (temp->isEod && search(root, s, i + 1, count + 1))
                return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    void insert(TrieNode* root, string& s) {
        TrieNode* temp = root;
        for (char& c : s) {
            if (temp->child[c - 'a'] == NULL) 
                temp->child[c - 'a'] = new TrieNode();
            
            temp = temp->child[c - 'a'];
        }
        temp->isEod = true;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& s : words) {
            insert(root, s);
        }
        vector<string> res;
        for (string& s : words) {
            memset(dp, -1, sizeof(dp));
            if (search(root, s, 0, 0))
                res.push_back(s);
        }
        return res;
    }
};
