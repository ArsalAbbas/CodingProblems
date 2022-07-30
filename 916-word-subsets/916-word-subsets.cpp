class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> freq2(125, 0), temp(125, 0);
        
        for(string w2:words2)
        {
            for(char ch:w2)
                temp[ch]++;
            
            for(char ch='a'; ch<='z'; ch++)
                freq2[ch] = max(freq2[ch], temp[ch]);
            
            //soft erasing
            for(char ch:w2)
                temp[ch]--;            
        }
        
        vector<string> res;
        
        vector<int> freq1(125, 0);
        for(string w1:words1)
        {           
            for(char ch:w1)
                freq1[ch]++;
            
            bool OK = true;
            
            for(char ch ='a'; ch <= 'z'; ch++)
                if (freq2[ch] > freq1[ch])
                {
                    OK = false;
                    break;
                }
            
            if (OK)
                res.push_back(w1);
            
            for(char ch:w1)
                freq1[ch]--;            
        }
        
        return res;
    }
};