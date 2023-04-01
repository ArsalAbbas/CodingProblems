//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i=0; i<M.size(); i++){
            st.push(i);
        }
        int x;
        while(st.size()>1){
            x=st.top();
            st.pop();
            // cout<<x<<endl;
            
            if(M[x][st.top()] || !M[st.top()][x]){
                continue;
            }
            else{
                st.pop();
                st.push(x);
            }
            
        }
        x=st.top();
        // cout<<x<<endl;
        for(int i=0; i<M.size(); i++) if(!M[i][x] && i!=x) return -1;
        for(int i=0; i<M.size(); i++) if(M[x][i] && i!=x) return -1;
        
        return x;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends