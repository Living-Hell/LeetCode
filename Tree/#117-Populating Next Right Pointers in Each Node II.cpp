// M1
// Using BFS through queue
// Faster than 30.26% (16ms)

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
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                if (i != n - 1)
                    node->next = q.front();
            }
        }
        return root;
    }
};

// M2
// Using Level order traversal in O(1) space
// Faster than 88.85% (8ms)

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        Node *node = root;
        while (node)
        {
            Node *head = new Node(0);
            Node *temp = head;
            while (node)
            {
                if (node->left)
                {
                    head->next = node->left;
                    head = head->next;
                }
                if (node->right)
                {
                    head->next = node->right;
                    head = head->next;
                }
                node = node->next;
            }
            node = temp->next;
        }
        return root;
    }
};