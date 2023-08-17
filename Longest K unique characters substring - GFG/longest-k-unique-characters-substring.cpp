//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n=s.length();
        int i=0;
        int j=0;
        int count=0;
        unordered_map<char,int> mp;
        mp.clear();
        int res=0;
        
        while(j<n){
           if(mp.find(s[j])!=mp.end()){
               mp[s[j]]++;
               if(count==k){
                   res=max(res,j-i+1);
               }
               j++;
               continue;
           }
           mp[s[j]]++;
           count++;
           
           if(count==k){
            //   cout<<"Count==k: "<<count<<" - "<<i<<","<<j<<endl;
               res=max(res,j-i+1);
               j++;
           }
           else if(count<k){
            //   cout<<"Count<k: "<<count<<" - "<<i<<","<<j<<endl;
               j++;
           }
           else if(count>k){
               
               while(count>k){
                //   cout<<"Count>k: "<<count<<" - "<<i<<","<<j<<endl;
                   mp[s[i]]--;
                   if(mp[s[i]]==0){
                       mp.erase(s[i]);
                       count--;
                   }
                   i++;
                   if(count==k){
                        res=max(res,j-i+1);
                   }
               }
               j++;
           }
        }
        return res==0? -1: res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends