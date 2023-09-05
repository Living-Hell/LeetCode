// M1
// Using Sieve of eratosthenes
// Faster than 50.8% (201ms)

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        vector<int> primes(n, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i * i < n; i++)
        {
            if (primes[i])
            {
                for (int j = i * i; j < n; j += i)
                    primes[j] = 0;
            }
        }
        int ans = accumulate(primes.begin(), primes.end(), 0);
        return ans;
    }
};