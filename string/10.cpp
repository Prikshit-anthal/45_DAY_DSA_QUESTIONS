class Solution {
public:
    string reverseWords(string s) {
        
        
        bool word=false;
        
        string curr;
        string ans;
        int n=s.length();
        
        for(int i=n-1;i>=0;i--)
        {
            
            if(s[i]==' ')
            {
                if(word)
                {
                    // ans+=curr;
                    ans=add_ulta(ans,curr);
                    ans.push_back(' ');
                    curr.erase();
                    word=false;  
                }
            }
            
            else {
                curr.push_back(s[i]);
                word=true;
            }
            
        }
        
        int p=ans.length();
        if(curr.length()==0) return ans.substr(0,p-1);
        
        return add_ulta(ans,curr);
    }
    
    string add_ulta(string a,string b)
    {
        int n=b.length();
        for(int i=n-1;i>=0;i--)
        {
            a.push_back(b[i]);
        }
        return a;
    }
};