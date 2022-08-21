/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long int rev=0,og=x;
        while(x>0){
            rev=(rev*10)+(x%10);
            x/=10;
        }
        if(rev!=og)
            return false;
        else
            return true;
        
    }
};
// @lc code=end

