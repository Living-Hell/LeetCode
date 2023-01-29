/*
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//M1
//Using BFS
//Faster than 73.47% (7ms)

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        unordered_map<Node*,Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node] = new Node(node->val);

        while(!q.empty()){
            Node* top = q.front();
            q.pop();
            for(auto i:top->neighbors){
                if(mp.find(i) == mp.end()){
                    q.push(i);
                    mp[i] = new Node(i->val);
                }
                mp[top]->neighbors.push_back(mp[i]);
            }
        }
        return mp[node];        
    }
};

//M2
//Using DFS
//Faster than 97.51%(3ms)

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        unordered_map<Node*,Node*> mp;
        stack<Node*> st;
        st.push(node);
        mp[node] = new Node(node->val);

        while(!st.empty()){
            Node* top = st.top();
            st.pop();
            for(auto i:top->neighbors){
                if(mp.find(i) == mp.end()){
                    st.push(i);
                    mp[i] = new Node(i->val);
                }
                mp[top]->neighbors.push_back(mp[i]);
            }
        }
        return mp[node];        
    }
};