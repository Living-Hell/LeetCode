//M1
//Binary Search
//Faster than 99.46% (7ms)

class Solution {
public:
    int focc(string s, char c){
        int n = s.size();
        int st = 0, e = n-1, m, ind=-1;

        while(st<=e){
            m = st + (e-st)/2;

            if(s[m] == c){
                ind = m;
                e = m-1;
            }
            else if(s[m] < c)
                st = m + 1;
            else 
                e = m - 1;
        }
        return ind;
    }

    int locc(string s, char c){
        int n = s.size();
        int st = 0, e = n-1, m, ind=-1;

        while(st<=e){
            m = st + (e-st)/2;

            if(s[m] == c){
                ind = m;
                st = m+1;
            }
            else if(s[m] < c)
                st = m + 1;
            else 
                e = m - 1;
        }
        return ind;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {

        int q = queries.size(), w = words.size();

        for(int i=0; i<q; i++)
            sort(queries[i].begin(),queries[i].end());

        for(int i=0; i<w; i++)
            sort(words[i].begin(),words[i].end());
        
        vector<int> wfreq, qfreq;

        for(int i=0; i<q; i++)
            qfreq.push_back(locc(queries[i],queries[i][0]) - focc(queries[i],queries[i][0]) + 1);
        for(int i=0; i<w; i++)
            wfreq.push_back(locc(words[i],words[i][0]) - focc(words[i],words[i][0]) + 1);
        
        vector<int> ans;
        sort(wfreq.begin(),wfreq.end());
        for(int i=0; i<q; i++){
            int pos = upper_bound(wfreq.begin(), wfreq.end(),qfreq[i]) - wfreq.begin();
            ans.push_back(w-pos);
        }

        return ans;

    }
};