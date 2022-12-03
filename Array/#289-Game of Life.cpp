//M1
//Simulation and Iteration
//Faster than 37.71% (4ms)

class Solution {
public:

    bool validrow(int row, int m){
        if(row>=0 && row<m) return true;
        return false;
    }

    bool validcol(int col, int n){
        if(col>=0 && col<n) return true;
        return false;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board[0].size();
        int m = board.size(); 
        vector<vector<int>> ans = board;
        vector<vector<int>> pos = {{-1,-1}, {-1,0}, {-1,1},  {0,1}, {1,1},  {1,0},  {1,-1},  {0, -1}};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count1 = 0;
                for(auto p : pos){
                    int r = i+p[0];
                    int c = j+p[1];
                    if(validrow(r,m) && validcol(c,n) && board[r][c] == 1)
                        count1++;
                }
                if(board[i][j] == 1 && (count1<2 || count1>3)) ans[i][j]=0;
                if(board[i][j] == 0 && count1==3) ans[i][j]=1;
            }
        }
        board = ans;
    }
};