/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0) return false;

        stack<char> tokens = stack<char>();
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                tokens.push(')');

            else if(s[i]=='[')
                tokens.push(']');
            
            else if(s[i]=='{')
                tokens.push('}');
            
            else {
            if((s[i]=='}'||s[i]==']'||s[i]==')') && !tokens.empty()){
                if(tokens.top()==s[i])
                    tokens.pop();
                else
                 return false;
            }
            else return false;
            }
                

        }
        if(tokens.empty())
            return true;
        return false;
        
    }
};
// @lc code=end

