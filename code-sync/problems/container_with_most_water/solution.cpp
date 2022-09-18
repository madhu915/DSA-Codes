class Solution {
public:
    int maxArea(vector<int>& height) {
        //2-pointer
        int start=0,end=height.size()-1,max=INT_MIN;
        int area;
        while(start<end){
            area=min(height[start],height[end])*(end-start);
        
            if(area>max)
                max=area;
            if(height[start]<height[end])
                start++;
            else
                end--;
        }
        return max;
    }
};