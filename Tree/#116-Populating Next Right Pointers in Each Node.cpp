// M1
// Using BFS through queue
// Faster than 37.89% (21ms)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int lvl = top.second;
            Node *node = top.first;
            if (node->left)
            {
                q.push({node->left, lvl + 1});
                q.push({node->right, lvl + 1});
            }
            if (!q.empty() and q.front().second == lvl)
                node->next = q.front().first;
        }
        return root;
    }
};

// M2
// Using BFS through Queue
// Faster than 96.58% (11ms)

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                    q.push(node->right);
                }
                if (i != n - 1)
                    node->next = q.front();
            }
        }
        return root;
    }
};