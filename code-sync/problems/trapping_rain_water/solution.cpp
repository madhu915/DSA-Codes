class Solution {
public:
    int trap(vector<int>& height) {
        //2-pointer
        int sum=0,l=0,r=height.size()-1;
        while(l<r){
            if(height[l]<=height[r]){
                int tmp=height[l++];
                while(height[l]<tmp){
                    sum+=tmp-height[l++];
                }
            }
            else{
                int tmp=height[r--];
                while(height[r]<tmp)
                    sum+=tmp-height[r--];
                }
            }
        return sum;

        }
};