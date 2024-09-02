//M1
//Using priority queue
//Faster than 40.00% (201 ms)

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        priority_queue<pair<int, int>> stones;
        for (int i = 0; i < n; i++) {
            stones.push({aliceValues[i] + bobValues[i], i});
        }
        int resAlice = 0, resBob = 0;
        while (stones.size() > 1) {
            auto [stoneA, indA] = stones.top();
            stones.pop();
            resAlice += aliceValues[indA];
            auto [stoneB, indB] = stones.top();
            stones.pop();
            resBob += bobValues[indB];
        }
        if (stones.size()) {
            auto [stoneA, indA] = stones.top();
            stones.pop();
            resAlice += aliceValues[indA];
        }

        if (resAlice == resBob)
            return 0;
        return resAlice > resBob ? 1 : -1;
    }
};
