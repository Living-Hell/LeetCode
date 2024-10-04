//M1
//Using Trie
//Faster than 55.18% (669ms)

class WordDictionary {
public:
    class TrieNode {
    public:
        TrieNode* child[26];
        bool end;
        TrieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
            end = false;
        }
    };
    TrieNode* node;
    WordDictionary() { node = new TrieNode(); }

    void addWord(string word) {
        TrieNode* temp = node;
        for (int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            if (temp->child[ind] == NULL) {
                temp->child[ind] = new TrieNode();
            }
            temp = temp->child[ind];
        }
        temp->end = true;
    }

    bool helper(string word, int ind, TrieNode* node) {
        if (ind == word.size())
            return node->end;
        if (word[ind] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->child[i] != NULL and
                    helper(word, ind + 1, node->child[i]))
                    return true;
            }
        } else {
            int curr = word[ind] - 'a';
            if (node->child[curr] != NULL and
                helper(word, ind + 1, node->child[curr]))
                return 1;
        }
        return 0;
    }

    bool search(string word) {
        TrieNode* temp = node;
        return helper(word, 0, temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
