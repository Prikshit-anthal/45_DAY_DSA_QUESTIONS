class Solution {
public:
    bool isValid(string s) {
        stack<char> x;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='{' || s[i]=='(' ||s[i]=='[')
            {     x.push(s[i]);
             cout<<"Pushing "<<s[i]<<endl;
            }
            else{
                if(x.empty())
                    return false;
                char top=x.top();
                char curr=s[i];
                
                cout<<"  "<<top<<"   "<<curr<<endl;
                if((top=='(' && curr==')') ||(top=='{' && curr=='}') || (top=='[' && curr==']') )
                {
                    x.pop();
                    
                }
                else{
                        return false;
                }
            }
            
            
            
        }
        if(x.empty())
        return true;
        else
            return false;
    }
};