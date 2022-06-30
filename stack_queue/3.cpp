class MyStack
{
    queue<int> temp;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        temp.push(x);
    }

    int pop()
    {
        int n = temp.size() - 1;

        while (n > 0)
        {
            int x = temp.front();
            temp.pop();
            temp.push(x);
            n--;
        }

        int ans = temp.front();
        temp.pop();

        return ans;
    }

    int top()
    {
        int n = temp.size() - 1;

        while (n > 0)
        {
            int x = temp.front();
            temp.pop();
            temp.push(x);
            n--;
        }

        int ans = temp.front();
        temp.pop();
        temp.push(ans);

        return ans;
    }

    bool empty()
    {
        return temp.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */