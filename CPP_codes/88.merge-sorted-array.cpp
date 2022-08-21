/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p=m+n-1,q=m-1,r=n-1;
        while(q>=0 && r>=0){
            if(nums1[q]<nums2[r]){
                nums1[p]=nums2[r];
                r--;
            }
            else{
                nums1[p]=nums1[q];
                q--;
            }
            p--;
        }
        while(r>=0){
            nums1[p--]=nums2[r];
            r--;            
        }
    }
};
// @lc code=end

