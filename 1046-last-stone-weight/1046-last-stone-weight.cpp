class Solution {
public:
     int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> game(stones.begin(),stones.end());
         int i,j;
        while(game.size()>1){
            
            i=game.top();
            game.pop();
            j=game.top();
            game.pop();
            if(i!=j) game.push(i-j);
        }
        if(game.empty()) return 0;
         else return game.top();
    }
};