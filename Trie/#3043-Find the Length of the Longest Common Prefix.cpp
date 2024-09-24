//M1
//Using Trie
//Faster than 51.86% (359 ms)

class Solution {
public:
    class TrieNode {
    public:
        TrieNode* children[10];
        bool isEOW;
        TrieNode() {
            for (int i = 0; i <= 9; i++) {
                children[i] = NULL;
            }
            isEOW = false;
        }
    };
    void insert(int n, TrieNode* node) {
        TrieNode* root = node;
        string s = to_string(n);
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - '0';
            if (root->children[curr] == NULL) {
                root->children[curr] = new TrieNode();
            }
            root = root->children[curr];
        }
        root->isEOW = true;
    }
    int search(TrieNode* node, int n) {
        TrieNode* root = node;
        string s = to_string(n);
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - '0';
            if (root->children[curr] == NULL)
                return i;
            root = root->children[curr];
        }
        return s.size();
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root1 = new TrieNode();
        for (int& i : arr1)
            insert(i, root1);
        int res = 0;
        for (int& i : arr2) {
            res = max(res, search(root1, i));
        }
        TrieNode* root2 = new TrieNode();
        for (int& i : arr2)
            insert(i, root2);
        for (int& i : arr1) {
            res = max(res, search(root2, i));
        }
        return res;
    }
};
