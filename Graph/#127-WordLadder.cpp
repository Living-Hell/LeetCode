//M1
//Using BFS
//Faster than 72.95% (103ms)

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if(it == wordList.end()) return 0;

        queue<pair<string,int>> q;
        unordered_set<string> st;
        int n = wordList.size();

        for(string s:wordList) st.insert(s);
        q.push(make_pair(beginWord,1));

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(int i=0; i<top.first.size(); i++){
                string s = top.first;

                for(int j=97; j<=122; j++){
                    if(j==s[i]) continue;

                    s[i] = j;

                    if(st.find(s)!=st.end()){
                        q.push(make_pair(s,top.second+1));
                        st.erase(s);
                    }
                        
                    if(s == endWord) return top.second+1;
                }
            }
        }
        return 0;
    }
};