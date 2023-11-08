// M1
// Using Hashmap
// Faster than 76.77% (167 ms)

class RandomizedSet
{
public:
    unordered_map<int, int> mp;
    vector<int> arr;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (!mp.count(val))
        {
            mp[val] = arr.size();
            arr.push_back(val);
            return 1;
        }
        return 0;
    }

    bool remove(int val)
    {
        if (mp.count(val))
        {
            int last = arr.back();
            mp[last] = mp[val];
            arr[mp[last]] = last;
            arr.pop_back();
            mp.erase(val);
            return 1;
        }
        return 0;
    }

    int getRandom()
    {
        int n = arr.size();
        n = rand() % n;
        return arr[n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */