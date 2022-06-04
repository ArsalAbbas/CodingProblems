class Solution {
public:
    void solve(int idx, int n, int mask1, int mask2, int mask3, vector<string>& temp, vector<vector<string>>& res){
        if(idx == n){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if((mask1>>i)&1 || (mask2>>i)&1 || (mask3>>i)&1) continue;
            int newmask1 = mask1|(1<<i), newmask2 = mask2|(1<<i);
            temp[idx][i] = 'Q';
            solve(idx+1, n, newmask1>>1, newmask2<<1, mask3|(1<<i), temp, res);
            temp[idx][i] = '.';
        }        
    }
	
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp;
        for(int i=0; i<n; i++){
            string s = "";
            for(int j=0; j<n; j++)
                s.push_back('.');
            temp.push_back(s);
        }
        solve(0, n, 0, 0, 0, temp, res);
        return res;
    }
};