class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char c;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' )
                st.push(s[i]);
            else{
                if(st.empty()) return false;
                
                c=st.top();
                
                st.pop();
                
                if ( c=='[' && s[i]==']')
                    continue;
                else if ( c=='{' && s[i]=='}')
                    continue;
                else if ( c=='(' && s[i]==')')
                    continue;
                else return false;
            }
            
        }
        return st.empty();
    }
};