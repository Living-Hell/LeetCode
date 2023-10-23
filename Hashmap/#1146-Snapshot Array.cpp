// M1
// Using Hashmap and Binary Search (Upper bound)
// Faster than 88.84% (358 ms)

class SnapshotArray
{
public:
    vector<map<int, int>> v;
    int snap_id;
    SnapshotArray(int length)
    {
        v.assign(length, {{0, 0}});
        snap_id = 0;
    }

    void set(int index, int val)
    {
        v[index][snap_id] = val;
    }

    int snap()
    {
        return snap_id++;
    }

    int get(int index, int snap_id)
    {
        auto i = v[index].upper_bound(snap_id);
        i--;
        return i->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */