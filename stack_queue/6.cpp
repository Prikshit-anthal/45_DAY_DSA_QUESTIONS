class Solution
{
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        int n = S.length();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            int fir, sec;

            int ascii = S[i];

            if (ascii >= 48 && ascii <= 57)
            {
                int x = S[i] - 48;
                st.push(x);
            }
            else
            {
                fir = st.top();
                st.pop();
                sec = st.top();
                st.pop();

                if (S[i] == '*')
                {
                    st.push(fir * sec);
                }

                if (S[i] == '+')
                {
                    st.push(fir + sec);
                }
                if (S[i] == '/')
                {
                    st.push(sec / fir);
                }

                if (S[i] == '-')
                    st.push(sec - fir);
            }
        }

        return st.top();
    }
};