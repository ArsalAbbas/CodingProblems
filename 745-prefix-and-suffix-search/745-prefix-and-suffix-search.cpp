struct TrieNode{
    struct TrieNode *children[27];
    int weight = 0;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->weight = 0;
 
    for (int i = 0; i < 27; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}

class WordFilter {
    struct TrieNode *trie;
public:
    WordFilter(vector<string>& words) {
        trie = getNode();
        for(int w = 0; w < words.size(); ++w){
            string word = words[w] + "{";
            for(int i = 0; i < word.length(); ++i){
                struct TrieNode *cur = trie;
                cur -> weight = w;
                
                for(int j = i; j < 2 * word.length() - 1; ++j){
                    int k = word[j % word.length()] - 'a';
                    if(!cur -> children[k])
                        cur -> children[k] = getNode();

                    cur = cur -> children[k];
                    cur -> weight = w;
                }
            }
            
        }
    }
    
    int f(string prefix, string suffix) {
        struct TrieNode *cur = trie;
        string word = suffix + "{" + prefix;
        for(int i = 0; i < word.length(); ++i){
            int k = word[i] - 'a';
            if(!cur -> children[k])
                return -1;
            cur = cur -> children[k];
        }
        return cur -> weight;
    }
};
