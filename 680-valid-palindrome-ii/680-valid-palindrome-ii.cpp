class Solution {
public:
    bool isPalin(string s){
        char temp;
        int l=s.length();
        string str=s;
        for(int i=0;i<l/2;i++){
            temp=str[i];
            str[i]=str[l-1-i];
            str[l-i-1]=temp;
        }
        if (str==s)
            return true;
        else
            return false;
    }
    bool validPalindrome(string s) {
        int l=s.length();
        string str="";
        int start=0;
        int end=l-1;
        while(start < end){

            if(s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            {
                break;
            }
		
        }

        

        str=s.substr(0,start)+s.substr(start+1);
        
        if (isPalin(str)) return true;
        
        str=s.substr(0,end)+s.substr(end+1);
        
        if (isPalin(str)) return true;

        return false;
        
    }
};