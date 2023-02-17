//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
        int i=0;
        int j=0;
        int N=txt.length();
        int K=pat.length();
        int res=0;
        
        map<char,int> mp;
        
        for(int i=0; i<K; i++) mp[pat[i]]++;
        int count=mp.size();
        //forxxorfxdofr
        //for
        //ij
        while(j< N){
            // cout<<i<<" "<<j<<endl;
            
            mp[txt[j]]--;
            
            if(mp.find(txt[j])!=mp.end()){
            // cout<<mp[txt[i]]<<" "<<mp[txt[j]]<<endl;
            // cout<<"Before:"<<count<<endl;
            if(mp[txt[j]]==0) count--;
            // cout<<"After:"<<count<<endl;
            }
            
            if(j-i+1<K){
            j++;
            continue;    
            } 
            
            if(j-i+1==K){
                
                if(count==0)
                res++;
                
                mp[txt[i]]++;
                if(mp.find(txt[i])!=mp.end()){
                    
                if(mp[txt[i]]==1)
                count++;
                }
                
                i++;
                j++;
                
            }
        }
        return res;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends