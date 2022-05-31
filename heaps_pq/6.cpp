class Solution
{
    string ans;

public:
    string reorganizeString(string s)
    {
        priority_queue<pair<int, char>> p_q;
        map<char, int> m;
        for (auto i : s)
        {
            m[i]++;
        }

        for (auto i : m)
        {
            p_q.push({i.second, i.first});
        }

        while (!p_q.empty())
        {

            auto first = p_q.top();
            p_q.pop();

            cout << " popped " << first.second << " ";

            ans.push_back(first.second);

            if (!p_q.empty())
            {
                auto second = p_q.top();
                p_q.pop();

                cout << " popped " << second.second << " ";

                ans.push_back(second.second);

                if (second.first != 1)
                    p_q.push({--second.first, second.second});
            }
            else
            {
                if (first.first > 1)
                    return "";
            }

            if (first.first != 1)
                p_q.push({--first.first, first.second});
        }

        return ans;
    }
};