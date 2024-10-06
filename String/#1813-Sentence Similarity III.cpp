//M1
//Using 2 pointers
//Faster than 40.09% (4ms)

class Solution {
public:
    void toWords(string& s, vector<string>& words) {
        int n = s.size();
        string temp = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp.push_back(s[i]);
            }
        }
        if (temp.size())
            words.push_back(temp);
    }
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> w1, w2;
        toWords(s1, w1);
        toWords(s2, w2);

        int n1 = w1.size(), n2 = w2.size();
        int st1 = 0, st2 = 0, end1 = n1 - 1, end2 = n2 - 1;
        
        while (st1 <= end1 and st2 <= end2) {
            if (w1[st1] == w2[st2]) {
                st1++, st2++;
            } else if (w1[end1] == w2[end2]) {
                end1--, end2--;
            } else
                return false;
        }
        return true;
    }
};
