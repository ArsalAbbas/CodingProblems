class Solution {
public:
    unordered_set<string> dp;
    
    string hash(vector<int> val, int idx) {
        string temp = "";
        temp += to_string(idx);
        temp += "#";
        sort(val.begin(), val.end());
        for(int i=0; i<4; i++) {
            temp += to_string(val[i]);
            temp += "#";
        }
        return temp;
    }
    
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%4) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        sum /= 4;
        vector<int> val(4, 0);
        return fun(nums, sum, val, 0);
    }
    
    bool fun(vector<int> &nums, int &sum, vector<int> &val, int idx) {
        if(idx==nums.size()) {
            for(int i=0; i<4; i++) if(val[i]!=sum) return false;
            return true;
        }
        string h = hash(val, idx);
        if(dp.count(h)) return false; 
        
        for(int i=0; i<4; i++) {
            if(val[i] + nums[idx] <= sum) {
                val[i] += nums[idx];
                if(fun(nums, sum, val, idx+1)) return true;
                val[i] -= nums[idx];
            }
        }
        dp.insert(h);
        return false;
    } 
};