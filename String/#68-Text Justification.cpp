//M1
//Using logic and simulation
//Faster than 100% (0ms)

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string temp = "";
        int n = words.size(), st = 0, len = 0;
        for (int i = 0; i < n; i++) {
            if (len + words[i].size() > maxWidth) {
                int count = i - st;
                len -= count;
                int gap = (maxWidth - len) / (count > 1 ? count - 1 : 1);
                int extraGap = (maxWidth - len) % (count > 1 ? count - 1 : 1);
                int smallGap = count - 1 - extraGap;
                string pad(gap, ' ');
                string extraPad(gap + 1, ' ');
                int j = st;
                while (j <= st + count and extraGap--) {
                    temp += words[j++] + extraPad;
                }
                while (j <= st + count and smallGap--) {
                    temp += words[j++] + pad;
                }
                temp += words[j];
                for (int ind = temp.size(); ind < maxWidth; ind++)
                    temp.push_back(' ');

                ans.push_back(temp);

                st = i;
                len = 0;
                temp = "";
            }
            len += words[i].size() + 1;
        }
        for (; st < n; st++)
            temp += words[st] + " ";
        temp.pop_back();
        
        for (int i = temp.size(); i < maxWidth; i++)
            temp.push_back(' ');

        if (temp.size())
            ans.push_back(temp);

        return ans;
    }
};
