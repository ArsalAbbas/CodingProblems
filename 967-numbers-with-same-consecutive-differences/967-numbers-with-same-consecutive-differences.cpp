class Solution {
public:
    vector<int> res;
    void solve(int n,int k,string str)
    {
        if(n<=0)
        {
            res.push_back(stoi(str));
            return;
        }
        if(str[str.length()-1]-k>='0')
            solve(n-1,k,str+char(str[str.length()-1]-k));
        if(str[str.length()-1]+k<='9' && str[str.length()-1]+k!=str[str.length()-1]-k)
            solve(n-1,k,str+char(str[str.length()-1]+k));
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++)
        {
            string temp{char('0'+i)};
            solve(n-1,k,temp);
        }
        return res;
    }
};