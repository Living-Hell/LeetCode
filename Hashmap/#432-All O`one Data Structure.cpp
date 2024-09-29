//M1
//Using hashmap and set (Increment and Decrement - O(logN) ; getMin and getMax - O(1)
//Faster than 88.56% (83ms)

class AllOne {
public:
    unordered_map<string, int> mp;
    set<pair<int, string>> st;
    AllOne() {}

    void inc(string key) {
        st.erase({mp[key], key});
        mp[key]++;
        st.insert({mp[key], key});
    }

    void dec(string key) {
        if (mp[key] == 1) {
            mp.erase(key);
            st.erase({1, key});
        } else {
            st.erase({mp[key], key});
            mp[key]--;
            st.insert({mp[key], key});
        }
    }

    string getMaxKey() { return st.size() > 0 ? st.rbegin()->second : ""; }

    string getMinKey() { return st.size() > 0 ? st.begin()->second : ""; }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
