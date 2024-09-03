//M1
//Using array (not so space-optimised approach)
//Faster than 80.08% (95ms)

class MyHashMap {
public:
    int map[1000001];
    MyHashMap() { memset(map, -1, sizeof(map)); }

    void put(int key, int value) { map[key] = value; }

    int get(int key) { return map[key]; }

    void remove(int key) { map[key] = -1; }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
