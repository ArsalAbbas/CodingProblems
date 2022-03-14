class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size()-1;
        int i=height.size()-1;
        int j=0;
        int max_area=0;
    while(i>=0 && j<height.size()){
        max_area=max(max_area,min(height[i],height[j])*abs(i-j) );
        if (height[i] > height[j]) {
                ++j;
            } else if (height[i] < height[j]) {
                --i;
            } else {
                --i, ++j;
            }
    }        
    return max_area;
    }
};