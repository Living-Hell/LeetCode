//M1
//Using Trie and recursion
//Faster than 69.35% (3ms)

class Trie {
public:
    Trie* children[26];
    bool isEnd;
    int tval;
    Trie() {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        tval = 0;
        isEnd = 0;
    }
};
class MapSum {
public:
    Trie* root;
    MapSum() { root = new Trie(); }

    void add(string s, Trie* root, int val) {
        Trie* temp = root;
        for (int i = 0; i < s.size(); i++) {
            int ind = s[i] - 'a';
            if (temp->children[ind] == NULL) {
                temp->children[ind] = new Trie();
            }
            temp = temp->children[ind];
        }
        temp->isEnd = 1;
        temp->tval = val;
    }
    int findSum(Trie* root, string pref) {
        int res = 0;
        Trie* temp = root;
        for (int i = 0; i < pref.size(); i++) {
            int ind = pref[i] - 'a';
            if (temp->children[ind] == NULL) {
                return 0;
            }
            temp = temp->children[ind];
        }
        totalSum(temp, res);
        return res;
    }

    void totalSum(Trie* root, int& res) {
        res += root->tval;
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                totalSum(root->children[i], res);
            }
        }
    }

    void insert(string key, int val) { add(key, root, val); }

    int sum(string prefix) { return findSum(root, prefix); }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
