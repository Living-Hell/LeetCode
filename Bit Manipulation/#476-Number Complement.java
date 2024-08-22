//M1
//Using bit manipulation
//Faster than 100% (0ms)

class Solution {
    public int findComplement(int num) {
        int res = 0, count = 0;
        while(num > 0){
            int mod = num%2;
            if(mod == 0){
                res += Math.pow(2,count);
            }
            num/=2;
            count++;
        }
        return res;
    }
}
