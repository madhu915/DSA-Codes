/*

Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

 

Example 1:

Input: nums = [2,1,2]
Output: 5
Example 2:

Input: nums = [1,2,1]
Output: 0

*/
#include<bits/stdc++.h>
using namespace std;
int lpt(vector<int>&arr){

    //sort in reverse order since sum is maximised
    sort(arr.rbegin(), arr.rend());
            int n = arr.size();
            
            for(int i=1; i<n-1; i++){
                int a = arr[i-1], b = arr[i], c = arr[i+1];
                if(a < b+c)
                    return a+b+c;
            }
            return 0;
}
int main(){
    vector<int>arr{2,2,1};
    cout<<lpt(arr);
    return 0;    
}        