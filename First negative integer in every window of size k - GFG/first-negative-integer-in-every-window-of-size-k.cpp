//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
                                                 
    queue<long long int> q;
    vector<long long> res;
    for(long long int i=0; i<n; i++){
        
        if(arr[i]<0) q.push(i);
        
        while((!q.empty()) &&  q.front()< i-k+1) q.pop();
        
        if(i>=k-1)
        res.push_back(!(q.empty())? arr[q.front()] : 0);
    }
    return res;
                                                 
 }