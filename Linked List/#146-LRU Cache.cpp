//M1
//Using Linked List and Hashmap
//Faster than 78.8% (338ms)

class LRUCache {
public:
    class dListNode {
    public:
        dListNode *next, *prev;
        int key, val;
        dListNode() {
            next = NULL;
            prev = NULL;
            key = -1;
            val = -1;
        }
        dListNode(int k, int v) {
            next = NULL;
            prev = NULL;
            key = k;
            val = v;
        }
    };
    dListNode *rear, *front;
    int size;
    unordered_map<int, dListNode*> mp;
    LRUCache(int capacity) {
        size = capacity;
        rear = new dListNode();
        front = new dListNode();
        rear->next = front;
        front->prev = rear;
    }

    void removeNode(dListNode *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void appendAtEnd(dListNode *node){
        dListNode *lastNode = front->prev;
        lastNode->next = node;
        node->prev = lastNode;
        front->prev = node;
        node->next = front;
    }

    void shiftToEnd(dListNode *node){
        removeNode(node);
        appendAtEnd(node);
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            shiftToEnd(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {        
        if(mp.find(key) != mp.end()){
            dListNode* node = mp[key];
            node->val = value;
            shiftToEnd(node);
        } else {
            if(mp.size() == size){
                dListNode *firstNode = rear->next;
                removeNode(firstNode);
                mp.erase(firstNode->key);
            }
            dListNode *newNode = new dListNode(key, value);
            mp[key] = newNode;
            appendAtEnd(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
