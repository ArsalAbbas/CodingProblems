//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void solve(vector<int> &ans, vector<int> input, vector<int> output){
    if(input.size()==0){
        // for(auto it: output)
        // cout<<it<<endl;
        ans.push_back(accumulate(output.begin(),output.end(),0));
        return;
    }
    
    vector<int> output1=output,output2=output;

    output2.push_back(input[0]);
    input.erase(input.begin()+0);
    
    solve(ans,input,output1);
    solve(ans,input,output2);
    
    return;
    
    
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        vector<int> output;
        solve(ans,arr, output );
        sort(ans.begin(),ans.end());
        // cout<<"-------------"<<endl;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends