// M1
// Using Array
// Faster than 53.99% (23ms)

class MyCircularQueue
{
public:
    vector<int> q;
    int front, back, size;
    MyCircularQueue(int k)
    {
        q.resize(k);
        front = 0, back = -1, size = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        back = (back + 1) % size;
        q[back] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        if (front == back)
            front = 0, back = -1;
        else
            front = (front + 1) % size;
        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : q[front];
    }

    int Rear()
    {
        return isEmpty() ? -1 : q[back];
    }

    bool isEmpty()
    {
        return back == -1;
    }

    bool isFull()
    {
        return !isEmpty() and (back + 1) % size == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */