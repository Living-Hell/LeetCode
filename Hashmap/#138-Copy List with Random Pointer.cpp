//M1
//Using Hashmap and recursion
//Faster than 28.13% (8ms)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void helper(Node* head, Node* root, map<Node*, Node*>& mp) {
        if (!head)
            return;
        if (!mp.contains(head->next)) {
            Node* temp = head->next;
            Node* tNext = NULL;
            if (temp)
                tNext = new Node(temp->val);
            root->next = tNext;
            mp[temp] = tNext;
        } else {
            root->next = mp[head->next];
        }
        if (!mp.contains(head->random)) {
            Node* rand = head->random;
            Node* tRand = NULL;
            if (rand)
                tRand = new Node(rand->val);
            root->random = tRand;
            mp[rand] = tRand;
        } else {
            root->random = mp[head->random];
        }
        helper(head->next, root->next, mp);
    }
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        Node* root = new Node(head->val);
        map<Node*, Node*> mp;
        mp[head] = root;
        helper(head, root, mp);
        return root;
    }
};
