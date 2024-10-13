//M1
//Using 2 priority queues (minHeap and maxHeap)
//Faster than 35.45% (275ms)

class MedianFinder {
public:
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
    MedianFinder() {}

    void addNum(int num) {
        maxPQ.push(num);
        minPQ.push(maxPQ.top());
        maxPQ.pop();
        if (maxPQ.size() < minPQ.size()) {
            maxPQ.push(minPQ.top());
            minPQ.pop();
        }
    }

    double findMedian() {
        return minPQ.size() == maxPQ.size() ? (minPQ.top() + maxPQ.top()) / 2.0
                                            : maxPQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
