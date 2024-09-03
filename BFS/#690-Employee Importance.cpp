//M1
//Using BFS with Dqeue
//Faster than 69.85% (24ms)

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;

        for (auto& e : employees) {
            mp[e->id] = e;
        }

        int res = 0;

        deque<Employee*> dq;
        dq.push_back(mp[id]);

        while (!dq.empty()) {
            Employee* e = dq.front();
            dq.pop_front();
            res += e->importance;
            for (int& id : e->subordinates)
                dq.push_back(mp[id]);
        }
        return res;
    }
};
