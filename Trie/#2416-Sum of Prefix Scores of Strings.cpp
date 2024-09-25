//M1
//Using Trie
//Faster than 56.36% (585ms)

class Solution {
public:
    class TrieNode {
    public:
        TrieNode* children[26];
        int val;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            val = 0;
        }
    };
    void insert(TrieNode* root, string& s) {
        TrieNode* temp = root;
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (temp->children[curr] == NULL) {
                temp->children[curr] = new TrieNode();
            }
            temp = temp->children[curr];
            temp->val++;
        }
    }
    int find(TrieNode* root, string& s) {
        TrieNode* temp = root;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            temp = temp->children[curr];
            res += temp->val;
        }
        return res;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        TrieNode* root = new TrieNode();
        for (string& s : words)
            insert(root, s);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            res[i] = find(root, words[i]);
        }
        return res;
    }
};
