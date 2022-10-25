//M1
//Using Sets
//Faser than 46.53%(459ms)

class Solution {
public:
    int partitionString(string s) {
        
        int n = s.size();
        unordered_set<char> st;
        int count=1;
        
        for(int i=0; i<n; i++){
            if(st.find(s[i]) != st.end()){
                count++;
                st.clear();
                st.insert(s[i]);
            }
            else
                st.insert(s[i]);
        }
        
        return count;
        
    }
};