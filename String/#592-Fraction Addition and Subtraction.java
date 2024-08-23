//M1
//Using Regex and simulation
//Faster than 27.98% (10ms)

class Solution {
    public int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public String fractionAddition(String expression) {
        String[] nums = expression.split("/|(?=[-+])");
        int n = nums.length;
        int res = Integer.parseInt(nums[1]);
        for (int i = 3; i < n; i += 2) {
            res = (res * Integer.parseInt(nums[i])) / (gcd(res, Integer.parseInt(nums[i])));
        }

        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            ans += Integer.parseInt(nums[i]) * (res / Integer.parseInt(nums[i + 1]));
        }
        int g = Math.abs(gcd(ans, res));
        String finalRes = Integer.toString(ans / g) + "/" + Integer.toString(res / g);
        return finalRes;
    }
}
