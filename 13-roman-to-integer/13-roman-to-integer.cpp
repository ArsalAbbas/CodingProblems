class Solution {
public:
    int romanToInt(string s) {
      unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int n=s.size();
        int num=0,i=0;
        while(i<n){
            if(s[i]=='I' && (i+1<n && (s[i+1]=='V' || s[i+1]=='X'))){
                num+= (mp[s[i+1]]-mp[s[i]]);
                i+=2;
            }
           else if(s[i]=='X'  && (i+1<n && (s[i+1]=='L' || s[i+1]=='C'))){
                num+=(mp[s[i+1]]-mp[s[i]]);
               i+=2;
           }
           else if(s[i]=='C'  && (i+1<n && (s[i+1]=='D' || s[i+1]=='M'))){
                num+= (mp[s[i+1]]-mp[s[i]]);
               i+=2;
           }
            else{
                num+=mp[s[i]];
                i++;
            }
        }
        return num;
        
    }
};