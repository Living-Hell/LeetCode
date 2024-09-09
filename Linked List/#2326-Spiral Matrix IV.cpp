//M1
//Using intuition and simulation
//Faster than 65.87% (162ms)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        int x = 0, y = 0, ind = 0;

        while (head) {
            while (head and x >= 0 and x < m and y >= 0 and y < n and res[x][y] == -1) {
                int val = head->val;
                head = head->next;
                res[x][y] = val;
                x += dir[ind].first, y += dir[ind].second;
            }
            x -= dir[ind].first, y -= dir[ind].second;
            ind = (ind + 1) % 4;
            x += dir[ind].first, y += dir[ind].second;
        }
        return res;
    }
};
