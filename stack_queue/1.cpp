class MyQueue
{
private:
    stack<int> primary, secondary;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        primary.push(x);
    }

    int pop()
    {
        if (secondary.empty())
        {
            if (primary.empty())
                return -1;
            while (!primary.empty())
            {
                int curr = primary.top();
                primary.pop();
                secondary.push(curr);
            }
            int curr = secondary.top();
            secondary.pop();
            return curr;
        }
        else
        {
            int curr = secondary.top();
            secondary.pop();
            return curr;
        }
    }

    int peek()
    {
        if (secondary.empty())
        {
            while (!primary.empty())
            {
                int curr = primary.top();
                primary.pop();
                secondary.push(curr);
            }
            int curr = secondary.top();
            return curr;
        }
        return secondary.top();
    }

    bool empty()
    {
        if (secondary.empty() && primary.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */