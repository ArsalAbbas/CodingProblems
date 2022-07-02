class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int hor=horizontalCuts[0],ver=verticalCuts[0];
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        for(int i=0;i<horizontalCuts.size()-1;++i)
        {
            hor=max(hor,(horizontalCuts[i+1]-horizontalCuts[i]));
        }
        for(int i=0;i<verticalCuts.size()-1;++i)
        {
            ver=max(ver,(verticalCuts[i+1]-verticalCuts[i]));
        }
        cout<<hor<<" "<<ver;
        return (1LL*hor*ver) % 1000000007;
    }
};