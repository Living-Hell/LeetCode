// M1
// USing 2 stacks
// Faster than 37.62% (3 ms)

class MyQueue
{
public:
    stack<int> st1, st2;
    MyQueue()
    {
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        while (st1.size() > 1)
        {
            st2.push(st1.top());
            st1.pop();
        }
        int res = st1.top();
        st1.pop();
        while (st2.size())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return res;
    }

    int peek()
    {
        int res;
        while (st1.size())
        {
            res = st1.top();
            st2.push(res);
            st1.pop();
        }
        while (st2.size())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return res;
    }

    bool empty()
    {
        return st1.empty();
    }
};
