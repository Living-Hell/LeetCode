//M1
//Using greedy and basic intuition
//Faster than 24.02% (38ms)

class Solution {
public:
    bool winnerOfGame(string colors) {
        int consA = 0, consB = 0, n = colors.size();
        for (int i = 1; i < n - 1; i++) {
            if (colors[i] == colors[i - 1] and colors[i] == colors[i + 1]) {
                if (colors[i] == 'A')
                    consA++;
                else
                    consB++;
            }
        }
        if (!consA)
            return 0;
        return consA > consB;
    }
};
