class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), res = 0;
        
        // Stores the masks of each word in words
        vector<int> mask(n, 0);
        
        for(int i = 0; i < n; i++) {
            for(char &ch: words[i])
                mask[i] |= 1 << (ch - 'a');
            
            for(int j = 0; j < i; j++) {
                if((mask[i] & mask[j]) == 0) {
                    res = max(res, int(words[i].length() * words[j].length()));
                }
            }
        }
        
        return res;
    }
};