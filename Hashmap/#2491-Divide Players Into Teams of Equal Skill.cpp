//M1
//Using hashmaps
//Faster than 9% (78ms)

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = 0;
        int n = skill.size();
        unordered_map<int, int> mp;
        for (int& i : skill) {
            sum += i;
            mp[i]++;
        }
        if (sum % (n / 2) != 0)
            return -1;
        int target = sum / (n / 2);
        long long res = 0;
        for (int& i : skill) {
            if (!mp.contains(target - i))
                return -1;
            res += i * (target - i);
            mp[target - i]--;
            if (mp[target - i] == 0)
                mp.erase(target - i);
        }
        return res / 2;
    }
};
