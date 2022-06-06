class Solution {
public:
    string defangIPaddr(string address) {
        string str="";
        for(int i=0; i< address.length() ; i++){
            
            if(address[i]=='.')
                str=str+"[.]";
            else
                str=str+address[i];
            
            
        }
        
        return str;
        
    }
};
// class Solution 
// {
// public:
//     string defangIPaddr(string ad) 
//     {
//         for(int i=0;i<ad.size();i++)
//         {
//             if(ad[i]=='.'){ad.replace(i,1,"[.]");i+=2;}  
//         }
//         return ad;
//     }
// };