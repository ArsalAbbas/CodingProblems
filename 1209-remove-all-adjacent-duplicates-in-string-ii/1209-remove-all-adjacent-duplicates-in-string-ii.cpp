class Solution {
public:
    string removeDuplicates(string s, int k) {
        //Stack approach: store pair (char, int) when frequency of element == k pop the pair & in           the last extract the string
        stack<pair<char, int>> st;
        
        for(int i=0; i<s.size(); i++)
        {
            //st-> (d, 1)
            if(st.empty() || st.top().first != s[i]) st.push({s[i], 1});
            else{ 
                auto topp = st.top();
                st.pop();
                st.push({s[i], ++topp.second}); //eee -> (e, 3)
            }
            
            if(st.top().second == k)   //(e, 3)-> k==3
                st.pop();
        }
    
        //extract ans
        string ans = "";
        while(!st.empty()){
            auto topp = st.top();
            st.pop();
            string res = string(topp.second, topp.first);
            ans += res;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};