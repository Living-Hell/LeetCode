//M1
//Using hashmap
//Faster than 5.3% (2275 ms)

class Solution {
public:
    int generateMask(string s) {
        int mask = 0;
        for (int i = 0; i < s.size(); i++) {
            int currChar = s[i] - 'a';
            mask |= (1 << currChar);
        }
        return mask;
    }
    int countSetBit(int mask) {
        int count = 0;
        while (mask > 0) {
            count += count & 1;
            count /= 2;
        }
        return count;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        map<int, int> mp;
        for (string& word : words) {
            int mask = generateMask(word);
            if (countSetBit(mask) > 7)
                continue;
            mp[mask]++;
        }
        int n = puzzles.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            string puzzle = puzzles[i];
            int pMask = generateMask(puzzle);
            for (auto& m : mp) {
                int mask = m.first, count = m.second;
                if ((mask & (1 << (puzzle[0] - 'a'))) and
                    ((mask & pMask) == mask))
                    res[i] += count;
            }
        }
        return res;
    }
};
