//M1
//Using intuition
//Faster than 34.33% (57ms)

class Solution {
public:
    bool check(string s) {
        int n = s.size();
        int st = 0, end = n - 1;
        while (st < end) {
            if (s[st] == '#')
                st++;
            if (s[end] == '#')
                end--;
            if (s[st] != s[end])
                return 0;
            st++, end--;
        }
        return 1;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        if (n <= 2)
            return 1;
        int diff = 0;
        int st = 0, end = n - 1;
        while (st < end) {
            if (s[st] != s[end])
                break;
            st++, end--;
        }
        if (st >= end)
            return 1;
        char c = s[st];
        s[st] = '#';
        if (check(s))
            return 1;
        s[st] = c;
        c = s[end];
        s[end] = '#';
        if (check(s))
            return 1;
        return 0;
    }
};
