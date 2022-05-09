class Solution {
public:
    vector<string> ans;
    map<char,string> mp;
    void solve(string digits,int index , string s)
    {
        if(index == digits.size())
        {
            ans.push_back(s);
            return;
        }
        for(auto it : mp[digits[index]])
        {
            s.push_back(it);
            solve(digits , index+1 , s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        if(digits.size() == 0)
        {
            return {};
        }
        string s = "";
        solve(digits,0 , s);
        return ans;
    }
};