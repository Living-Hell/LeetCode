//M1
//Using Recursion
//Faster than 7.93% (170ms)

class Solution {
    int res = 0;
    char[] vowel = { 'a', 'e', 'i', 'o', 'u' };

    public void solve(int n, int prev) {
        if (n == 0) {
            res++;
            return;
        }

        for (int i = 0; i < 5; i++) {
            if (vowel[i] >= prev)
                solve(n - 1, vowel[i]);
        }

    }

    public int countVowelStrings(int n) {
        solve(n, 0);
        return res;
    }
}
