class Solution {
public:
    int res = 0;
    unordered_map<char,vector<int>> rec;
    void solve(string s, int index, int last){
        if(index == s.size()){
            res++;
            return;
        }
        for(auto it:rec[s[index]]){
            if(it > last){
                solve(s,index+1,it);
                return;
            }
        }
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        for(int i=0;i<s.size();i++){
            rec[s[i]].push_back(i);
        }
        for(auto it:words){
            solve(it,0,-1);
        }
        return res;
    }
};