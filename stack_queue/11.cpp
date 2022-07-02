class StockSpanner
{

    stack<int> s;
    vector<int> vals;

public:
    StockSpanner()
    {
        vals.push_back(0);
        s.push(0);
    }

    int next(int price)
    {

        int n = vals.size();
        int idx = n;
        while (!s.empty())
        {
            if (vals[s.top()] <= price)
            {
                s.pop();
            }
            else
            {
                idx -= s.top();
                break;
            }
        }
        s.push(n);
        vals.push_back(price);

        return idx;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */