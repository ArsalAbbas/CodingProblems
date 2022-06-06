class Solution {
public:
    string defangIPaddr(string address) {
        string str="";
        for(int i=0; i< address.length() ; i++)
            str=address[i]=='.'?str+"[.]":str+address[i];       
        return str;
}};
