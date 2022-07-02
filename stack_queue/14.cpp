class Solution
{
public:
    int evalRPN(vector<string> &S)
    {

        int n = S.size();

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            int fir, sec;

            int ascii = S[i][0];
            int c = S[i].length();

            if (c != 1 || (ascii >= 48 && ascii <= 57))
            {
                int x = stoi(S[i]);
                st.push(x);
            }
            else
            {
                fir = st.top();
                st.pop();
                sec = st.top();
                st.pop();

                if (S[i][0] == '*')
                {
                    st.push(fir * sec);
                }

                if (S[i][0] == '+')
                {
                    st.push(fir + sec);
                }
                if (S[i][0] == '/')
                {
                    st.push(sec / fir);
                }

                if (S[i][0] == '-')
                    st.push(sec - fir);
            }
        }

        return st.top();
    }
};
