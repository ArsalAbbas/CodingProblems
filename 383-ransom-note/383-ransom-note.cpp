class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
       unordered_map<char,int> mp;
        
        for(char ch='a'; ch<='z' ; ch++)
           mp[ch]=0;
        
        for(int i=0; i< magazine.length() ; i++)
           mp[magazine[i]]++;
        
        for(int i=0; i< ransomNote.length();i++)
            mp[ransomNote[i]]--;
        
        for(char ch='a'; ch<='z' ; ch++){
            if(mp[ch]<0)
                return false;
        }
        return true;
        
        
    }
};