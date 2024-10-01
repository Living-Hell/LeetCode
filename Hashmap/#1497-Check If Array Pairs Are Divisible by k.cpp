//M1
//Using hashmap
//Faster than 21.43% (155 ms)

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int& i : arr) {
            mp[((i % k) + k) % k]++;
        }

        for (int i = 0; i < k; i++) {
            if (i == 0) {
                if (mp[i] & 1) {
                    return false;
                }
                continue;
            }
            if (mp[i] != mp[k - i])
                return false;
        }
        return true;
    }
};
