class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
     priority_queue <pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p_q;  
        
        p_q.push({matrix[0][0],{0,0}});
        matrix[0][0]=-1e9;
        
        int n=matrix.size();
        
        int counter=0;
        while(!p_q.empty())
        {
            auto curr=p_q.top();
            p_q.pop();
            counter++;
            if(counter==k)
                return curr.first;
            
            int x=curr.second.first,y=curr.second.second;
            
            if(x!=n-1 && matrix[x+1][y]>matrix[x][y])
            {p_q.push({matrix[x+1][y],{x+1,y}});
             
             cout<<"Pushing "<<matrix[x+1][y]<<" ";
             matrix[x+1][y]=-1e9;
             
            }
            
            if(y!=n-1 && matrix[x][y+1]>matrix[x][y])
            {p_q.push({matrix[x][y+1],{x,y+1}});
             
             cout<<"Pushing "<<matrix[x][y+1]<<" ";
             
             matrix[x][y+1]=-1e9;
        
            }
            }
        
        return -1;
    }
};


//better exist  