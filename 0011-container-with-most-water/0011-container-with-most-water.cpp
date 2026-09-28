class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0, right=heights.size()-1,maxwater=0;
        while(left<right){
            int height=min(heights[left],heights[right]);
            int width=right-left;
            int area=height*width;
            maxwater=max(maxwater,area);
            if(heights[left]<heights[right]){
                left++;
            }else{
                right--;
            }
    }
    return maxwater;
    }
};