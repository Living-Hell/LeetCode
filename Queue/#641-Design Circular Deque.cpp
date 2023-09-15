// M1
// Using array
// Faster than 88.35% (19ms)

class MyCircularDeque
{
public:
    vector<int> dq;
    int front, back, size, count;
    MyCircularDeque(int k)
    {
        dq.resize(k);
        front = 0, back = -1, size = k, count = 0;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        front = (front - 1 + size) % size;
        dq[front] = value;
        count++;
        if (count == 1)
            back = front;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        back = (back + 1) % size;
        dq[back] = value;
        count++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % size;
        count--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        back = (back - 1 + size) % size;
        count--;
        return true;
    }

    int getFront()
    {
        return isEmpty() ? -1 : dq[front];
    }

    int getRear()
    {
        return isEmpty() ? -1 : dq[back];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */