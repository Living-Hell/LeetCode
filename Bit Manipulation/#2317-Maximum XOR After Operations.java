//M1
//Using bit manipulation
//Faster than 6.17% (46ms)

class Solution {
    public int maximumXOR(int[] nums) {
        int[] a = new int[32];
        Arrays.fill(a,0);
        for(int num : nums){
            int count = 0;
            while(num > 0){
                a[count++] += num%2;
                num /= 2;
            }
        }
        int res = 0;
        for(int i=0; i<32; i++){ 
            if(a[i] > 0){
                res += Math.pow(2,i);
            }
        }
        return res;
    }
}
