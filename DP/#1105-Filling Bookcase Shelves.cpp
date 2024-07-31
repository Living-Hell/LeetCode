//M1
//Using dp and memoisation
//Faster than 42.24% (7ms)

class Solution {
public:
    int dp[1001][1001]; 
    int solve(vector<vector<int>>& books, int shelfWidth, int i, int remWidth, int maxHt) {
        if (i >= books.size())
            return maxHt;
        
        if(dp[i][remWidth] != -1) return dp[i][remWidth];

        int resa = INT_MAX, resb = INT_MAX;

        int thicc = books[i][0], ht = books[i][1];

        if (thicc <= remWidth) 
            resa = solve(books, shelfWidth, i + 1, remWidth - thicc,max(maxHt, ht));

        resb = maxHt + solve(books, shelfWidth, i + 1, shelfWidth-thicc, ht);

        return dp[i][remWidth] = min(resa,resb);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        return solve(books,shelfWidth,0,shelfWidth,0);
    }
};
