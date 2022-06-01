class Solution
{
public:
    int minDeletions(string s)
    {
        map<char, int> alpha;
        map<int, int> freq;

        for (auto i : s)
        {
            alpha[i]++;
        }
        for (auto i : alpha)
        {
            freq[i.second]++;
        }

        // reverse itr used
        map<int, int>::reverse_iterator j = freq.rbegin();

        int delet = 0;
        for (; j != freq.rend(); j++)
        {
            cout << "Freq " << j->first << " " << j->second << endl;
            if (j->second > 1)
            {
                if (j == freq.rend())
                {
                    delet += j->second - 1;
                    cout << "changing dalit " << delet << endl;
                    break;
                }

                // necessary becoz dont want to create 0,-1 type frequencies
                if (j->first > 1)
                    freq[j->first - 1] += j->second - 1;

                delet += j->second - 1;
                cout << "changing dalit " << delet << endl;
            }
        }
        return delet;
    }
};

