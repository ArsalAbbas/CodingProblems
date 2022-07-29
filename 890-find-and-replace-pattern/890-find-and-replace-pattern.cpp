class Solution {
public:
    bool check(string s , string pattern){
        unordered_map <char , char> m;
        unordered_map <char , char> m2;
  
         int i=0;
 
    for (auto c :s)
    {
        if(m.find(pattern[i])==m.end())                             
           {
                if(m2.find(c)==m2.end())
                    {
                    m[pattern[i]]=c;
                    m2[c]=pattern[i];
            }
            else
                return false;
            
           }
        else{
            
            if(m[pattern[i]]!=c)
                return false;
        }
        i++;
    }
        return i==pattern.size();
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
         vector<string> res;
        for(string s:words){
            if(check(s,pattern))
                res.push_back(s);
        }
        return res;
    }
};