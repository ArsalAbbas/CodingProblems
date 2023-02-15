//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
        
        int left=0;
        int right=left+K-1;//1
        
        long sum=0;
        long maxSum=INT_MIN;
        
        for(int i=left  ;  i<=right;  i++)
            sum+=arr[i];

             maxSum=max(maxSum, sum);

        while(right< N-1){
            sum=sum-arr[left++]+arr[++right];
            maxSum=max(maxSum, sum);
        }
        // cout<<maxSum<<endl;
        return maxSum;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends