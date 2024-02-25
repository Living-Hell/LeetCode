// M1
// Using 2 Queues
// Faster than 38.7% (3 ms)

class MyStack
{
public:
    queue<int> q1, q2;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        while (q2.size())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }

    int top()
    {
        int res;
        while (q1.size())
        {
            res = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        while (q2.size())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return res;
    }

    bool empty()
    {
        return q1.empty();
    }
};

// M2
// Using 1 Queue
// Faster than 100% (0 ms)

class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        int n = q.size();
        while (--n)
        {
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        return res;
    }

    int top()
    {
        int n = q.size();
        while (--n)
        {
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        q.push(res);
        return res;
    }

    bool empty()
    {
        return q.empty();
    }
};
