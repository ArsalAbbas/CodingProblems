class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        map<int,vector<int>,greater<int>> mp2;
        for(auto i: mp){
            mp2[i.second].push_back(i.first);
        }
        int count = 0;
        int removed = 0;
        for(auto i:mp2){
            for(int j=0;j<i.second.size();j++){
                if(removed < (n+1)/2){
                    removed += i.first;
                    count++;
                }
            }
        }
        return count;
    }
};