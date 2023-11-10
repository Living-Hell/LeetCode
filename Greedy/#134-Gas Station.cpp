// M1
// Using greedy approach
// Faster than 60.97% (113 ms)

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int tgas = 0;
        for (int i = 0; i < n; i++)
        {
            tgas += gas[i] - cost[i];
        }
        if (tgas < 0)
            return -1;

        int fuel = 0, st = 0;

        for (int i = 0; i < n; i++)
        {
            fuel += gas[i] - cost[i];
            if (fuel < 0)
            {
                st = i + 1;
                fuel = 0;
            }
        }
        return st;
    }
};
