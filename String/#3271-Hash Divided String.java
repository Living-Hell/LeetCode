//M1
//Using for loop
//Faster than 96.34% (2ms)

class Solution {
    public String stringHash(String s, int k) {
        StringBuilder res = new StringBuilder();
        int n = s.length();
        for(int i=0; i<n; i+=k){
            int hash = 0;
            for(int j=i; j<i+k; j++){
                hash += s.charAt(j) - 'a';
            }
            hash %= 26;
            res.append((char)(hash + 'a'));
        }
        return res.toString();
    }
}
