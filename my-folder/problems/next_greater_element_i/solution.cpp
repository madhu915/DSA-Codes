class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> great;
        stack<int> data;
        vector<int>res;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!data.empty()&&data.top()<=nums2[i])
                data.pop();
            great[nums2[i]]=data.empty()?-1:data.top();
            data.push(nums2[i]);            
        }
        for(auto x:nums1){
            res.push_back(great[x]);
        }
        return res;
    }
};