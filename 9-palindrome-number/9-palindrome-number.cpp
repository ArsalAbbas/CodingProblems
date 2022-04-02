class Solution {
public:
    bool isPalindrome(int x) {
        int num=0;
        string str=to_string(x);
        int start=0,end=str.length()-1;
        while(start<end){
            if(str[start]!=str[end])
                return false;
            start++;
            end--;
        }
        return true;
        }
};