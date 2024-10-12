//M1
//Using trie and recusrion
//Faster than 47.51% (945 ms)

class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[26];
        bool isEnd;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
                isEnd = 0;
            }
        }
    };
    TrieNode* root = new TrieNode();
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    void insert(string s) {
        TrieNode* temp = root;
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (temp->child[curr] == NULL) {
                temp->child[curr] = new TrieNode();
            }
            temp = temp->child[curr];
        }
        temp->isEnd = true;
    }
    void helper(vector<vector<char>>& board, vector<vector<bool>>& vis, vector<string>& res, TrieNode *node, string temp, int i, int j) {
        if(node->isEnd){
            res.push_back(temp);
            node->isEnd = false;
        }
        for(auto &p:dir){
            int x = i + p.first, y = j + p.second;
            if (x < 0 or x >= board.size() or y < 0 or y >= board[0].size() or vis[x][y]) 
                continue;
            char ch = board[x][y];
            if(node->child[ch-'a']){
                vis[x][y] = 1;
                helper(board, vis, res, node->child[ch-'a'], temp+ch, x, y);
                vis[x][y] = 0;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string& word : words)
            insert(word);
        vector<string> res;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char ch = board[i][j];
                if(root->child[ch - 'a']){
                    vis[i][j] = 1;
                    helper(board, vis, res, root->child[ch-'a'], string(1, ch), i, j);
                    vis[i][j] = 0;
                }
            }
        }
        return res;
    }
};
