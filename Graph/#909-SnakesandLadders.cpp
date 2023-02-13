//M1
//Using BFS
//Faster than 95.63% (14ms)

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int,int>> q;
        vector<bool> visited(n*n+1,0);
        q.push({1,0});
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int score = top.first, moves = top.second;
            if(score == n*n) return moves;

            for(int i=score+1; i<=min(score+6, n*n); i++){
                int r = (i-1)/n;
                int c;
                if(r&1) c = n - (i-1)%n -1;
                else c = (i-1)%n;
                r  = n-1-r;
                if(board[r][c]!= -1 && !visited[board[r][c]]){
                    q.push({board[r][c],moves+1});
                    visited[board[r][c]] = 1;
                }
                else if(board[r][c] == -1 && !visited[i]){
                    visited[i]=1;
                    q.push({i,moves+1});
                }
            }
        }
        return -1;
    }
};