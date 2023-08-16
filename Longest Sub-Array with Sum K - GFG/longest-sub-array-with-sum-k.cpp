//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    {
        int currSum=0;
        int ans=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0; i<n; i++)
        {
            currSum+=A[i];
            
            if(mp.find(currSum)==mp.end())
                    mp[currSum]=i;
            
            if(mp.find(currSum-k)!=mp.end())
                    ans=max(ans,i-mp[currSum-k]);
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends