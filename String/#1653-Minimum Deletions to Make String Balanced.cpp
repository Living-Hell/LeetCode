//M1
//Using simulation and DP
//Faster than 55.5% (93ms)

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int res=INT_MAX, counta=0, countb=0;

        for(int i=0; i<n; i++)
            if(s[i] == 'a') 
                counta++;
        
        res = counta;

        for(int i=0; i<n; i++){
            if(s[i] == 'a')
                counta--;
            else
                countb++;
            res = min(res, counta + countb);
        }

        return res;
    }
};

//M2
//Using prefix sum
//Faster than 38.5% (105ms)

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int res = INT_MAX, counta = 0;
        vector<int> freqa(n), freqb(n);

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                counta++;
            freqa[i] = counta;
            freqb[i] = i+1 - counta;
        }

        if (!counta or counta == n)
            return 0;

        for (int i = 0; i < n; i++) {
            res = min(res, freqb[i] + freqa[n - 1] - freqa[i] - (s[i] == 'b'));
        }

        return res;
    }
};
