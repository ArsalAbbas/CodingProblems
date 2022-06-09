class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        string res="";
        string larger=i>j?a:b;
        int carry=0;
        while(i>=0 && j>=0){
            
            if(a[i]=='1' && b[j]=='0'){
                
                if(carry==1)
                    res="0"+res;
                else
                res="1"+res;
            }
            if(a[i]=='0' && b[j]=='0'){
                
                if(carry==1){
                    res="1"+res;
                    carry=0;
                }
                else
                res="0"+res;
            }
            
            if(a[i]=='0' && b[j]=='1'){
                 if(carry==1)
                    res="0"+res;
                else
                res="1"+res;
            }
            if(a[i]=='1' && b[j]=='1'){
                
                if (carry==1)
                res="1"+res;
                else res="0"+res;
                carry=1;
            }

            i--;
            j--;
            
        }


        int x=max(i,j);

        larger=larger.substr(0,x+1);
        while(carry==1 && x>=0){
            
            if(larger[x]=='0'){
                
                res="1"+res;
                carry=0;
            }
            else{
                
                res="0"+res;
            }
                
            x--;
            
        }
 
        res=larger.substr(0,x+1)+res;
        if(carry==1)
            res="1"+res;
        return res;
        
    }
};