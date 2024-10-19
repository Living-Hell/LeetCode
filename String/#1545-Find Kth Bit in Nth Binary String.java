//M1
//Using for loop and simple intuition
//Faster than 20.43% (120 ms)

class Solution {
    public char findKthBit(int n, int k) {
        StringBuilder s = new StringBuilder("0");
        while (n - 1 > 0) {
            StringBuilder temp = new StringBuilder(s);
            temp.reverse();
            s.append('1');
            for (int i = 0; i < temp.length(); i++) {
                char c = temp.charAt(i);
                if (c == '0') {
                    s.append('1');
                } else {
                    s.append('0');
                }
            }
            n--;
        }
        return s.charAt(k - 1);
    }
}
