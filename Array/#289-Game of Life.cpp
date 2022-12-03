//M1
//Simulation and Iteration
//Faster than 37.71% (4ms)

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board[0].size();
        int m = board.size(); 
        vector<vector<int>> ans (m,vector<int>(n,0));
        vector<vector<int>> pos = {{-1,-1}, {-1,0}, {-1,1},  {0,1}, {1,1},  {1,0},  {1,-1},  {0, -1}};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count1 = 0;
                for(auto p : pos){
                    int r = i+p[0];
                    int c = j+p[1];
                    if(r>=0 && r<m && c>=0 && c<n && board[r][c] == 1)
                        count1++;
                }
                if(board[i][j] == 1){
                    if(count1<2 || count1>3) 
                        ans[i][j]=0;
                    else
                        ans[i][j]=1;
                }
                if(board[i][j] == 0 && count1==3) ans[i][j]=1;
            }
        }
        board = ans;
    }
};

//M2
//Simulation and Iteration using O(1) space
//Faster than 53.64% (3ms)

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board[0].size();
        int m = board.size(); 
        vector<vector<int>> pos = {{-1,-1}, {-1,0}, {-1,1},  {0,1}, {1,1},  {1,0},  {1,-1},  {0, -1}};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count1 = 0;
                for(auto p : pos){
                    int r = i+p[0];
                    int c = j+p[1];
                    if(r>=0 && r<m && c>=0 && c<n && (board[r][c] == 1 || board[r][c] == 2))
                        count1++;
                }
                if(board[i][j] == 1){
                    if(count1<2 || count1>3) 
                        board[i][j]=2;
                }
                if(board[i][j] == 0 && count1==3) board[i][j]=3;
            }
        }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                board[i][j]%=2;
    }
};