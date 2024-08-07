//M1
//Using Segment Tree
//Faster than 17.78% (394ms)

class LUPrefix {
public:
    vector<int> segTree;
    int len;
    int answer;
    void Update(int ind, int st, int end, int updateInd, int val) {
        if (updateInd < st or updateInd > end)
            return;

        if (st == end) {
            segTree[ind] = val;
            return;
        }
        int mid = st + (end - st) / 2;
        Update(2 * ind + 1, st, mid, updateInd, val);
        Update(2 * ind + 2, mid + 1, end, updateInd, val);

        segTree[ind] = segTree[2 * ind + 1] + segTree[2 * ind + 2];
    }
    int Query(int ind, int st, int end, int qst, int qend) {
        if (qend < st or qst > end)
            return 0;
        if (qst <= st and qend >= end)
            return segTree[ind];
        int mid = st + (end - st) / 2;
        return Query(2 * ind + 1, st, mid, qst, qend) +
               Query(2 * ind + 2, mid + 1, end, qst, qend);
    }

    LUPrefix(int n) {
        len = n;
        answer = 0;
        segTree.resize(4 * n, 0);
    }

    void upload(int video) { Update(0, 0, len - 1, video - 1, 1); }

    int longest() {
        int low = answer;
        int high = len;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (Query(0, 0, len - 1, 0, mid - 1) == mid) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
