//M1
//Using frequency table
//Faster than 86.43% (6ms)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int a[1001] = {0}, n = arr.size();
        for (int i = 0; i < n; i++) {
            a[target[i]]++;
            a[arr[i]]--;
        }
        for (int i = 0; i < 1001; i++) {
            if (a[i] != 0)
                return 0;
        }
        return 1;
    }
};
