// M1
// Using sets and BFS
// Faster than 100% (0ms)

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        unordered_set<string> st(bank.begin(), bank.end());
        unordered_set<string> vis;
        queue<pair<string, int>> q;
        vis.insert(startGene);
        q.push({startGene, 0});
        int res = 0;
        char strands[4] = {'A', 'G', 'C', 'T'};

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            string gene = top.first;
            int mut = top.second;
            if (gene == endGene)
                return mut;

            for (int i = 0; i < 8; i++)
            {
                string gene1 = gene;
                for (int j = 0; j < 4; j++)
                {
                    gene1[i] = strands[j];
                    if (!vis.contains(gene1) and st.contains(gene1))
                    {
                        q.push({gene1, mut + 1});
                        vis.insert(gene1);
                    }
                }
            }
        }
        return -1;
    }
};