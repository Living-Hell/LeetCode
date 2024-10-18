//M1
//Using HashSet
//Faster than 59.01% (60ms)

class Solution {
    public int reverseDigits(int num){
        int res = 0;
        while(num > 0){
            res = res*10 + num%10;
            num/=10;
        }
        return res;
    }
    public int countDistinctIntegers(int[] nums) {
        HashSet<Integer> st = new HashSet<>();
        for(int num : nums){
            st.add(num);
            st.add(reverseDigits(num));
        }
        return st.size();
    }
}
